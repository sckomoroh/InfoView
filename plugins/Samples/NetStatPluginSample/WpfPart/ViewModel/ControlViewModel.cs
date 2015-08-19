using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.ObjectModel;
using System.Xml;
using System.Net;
using System.Threading.Tasks;
using System.Windows.Threading;

namespace NetStatPluginSample.WpfPart.ViewModel
{
    public class ControlViewModel
    {
        public ControlViewModel()
        {
            Items = new ObservableCollection<ViewModelItem>();
        }

        public ObservableCollection<ViewModelItem> Items { get; set; }

        public void ResetModel()
        {
            Items.Clear();
        }

        public void BuildModel(string folder)
        {
            var dispatcher = Dispatcher.CurrentDispatcher;
            Task.Factory.StartNew(() => {
                var fileName = Path.Combine(folder, @"NetStat\NetStat.xml");

                var document = new XmlDocument();
                document.Load(fileName);

                var rootElement = document.DocumentElement;
                Console.WriteLine(rootElement.Name);

                var netStatInfoCollection = rootElement.GetElementsByTagName("netStatInfo");
                foreach (var netStatInfoElement in netStatInfoCollection)
                {
                    var netStatInfo = ParseNetStatItem(netStatInfoElement as XmlElement);
                    dispatcher.Invoke(new Action(() => { Items.Add(new ViewModelItem(netStatInfo)); }));
                }
            });
        }

        private static NetStatInfo ParseNetStatItem(XmlElement element)
        {
            var processIdElement = element.GetElementsByTagName("processId").Item(0);
            var processNameElement = element.GetElementsByTagName("processName").Item(0);
            var protocolTypeElement = element.GetElementsByTagName("protocolType").Item(0);
            var stateElement = element.GetElementsByTagName("state").Item(0);
            var localEndpointElement = element.GetElementsByTagName("localEndPoint").Item(0) as XmlElement;
            var remoteEndpointElement = element.GetElementsByTagName("remoteEndPoint").Item(0) as XmlElement;

            var processName = processNameElement.InnerText;
            var processId = processIdElement.InnerText;
            var protocolType = protocolTypeElement.InnerText;
            var state = stateElement.InnerText;
            var localEndpoint = ParseEndpoint(localEndpointElement);
            var remoteEndpoint = ParseEndpoint(remoteEndpointElement);

            var result = new NetStatInfo
            {
                ProcessId = processId,
                ProcessName = processName,
                ProtocolType = protocolType,
                State = state,
                LocalEndpoint = localEndpoint,
                RemoteEndpoint = remoteEndpoint
            };

            return result;
        }

        private static Endpoint ParseEndpoint(XmlElement element)
        {
            if (element == null)
            {
                return null;
            }

            if (!element.HasChildNodes)
            {
                return null;
            }

            var portElement = element.GetElementsByTagName("a:m_Port").Item(0) as XmlElement;
            var addressElement = element.GetElementsByTagName("a:m_Address").Item(0) as XmlElement;

            var port = portElement.InnerText;
            var address = ParseAddress(addressElement);

            var result = new Endpoint
            {
                Port = port,
                Address = address
            };

            return result;
        }

        private static Address ParseAddress(XmlElement element)
        {
            var familyElement = element.GetElementsByTagName("a:m_Family").Item(0) as XmlElement;
            var addressElement = element.GetElementsByTagName("a:m_Address").Item(0) as XmlElement;

            var addr = long.Parse(addressElement.InnerText);
            var family = familyElement.InnerText;
            var ipAddr = new IPAddress(addr);

            var address = new Address
            {
                Family = family,
                IPAddress = ipAddr
            };

            return address;
        }
    }
}
