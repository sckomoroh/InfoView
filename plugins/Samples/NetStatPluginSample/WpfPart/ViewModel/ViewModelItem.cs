using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NetStatPluginSample.WpfPart.ViewModel
{
    public class ViewModelItem
    {
        private NetStatInfo _netStatInfo;
        private string _localAddress = null;
        private string _remoteAddress = null;

        public ViewModelItem(NetStatInfo netStatInfo)
        {
            _netStatInfo = netStatInfo;
        }

        public string Type
        {
            get
            {
                return _netStatInfo.ProtocolType;
            }
        }

        public string ProcessId
        {
            get
            {
                return _netStatInfo.ProcessId;
            }
        }

        public string LocalAddress
        {
            get
            {
                if (_localAddress == null)
                {
                    _localAddress = string.Format(
                    "{0}:{1}",
                    _netStatInfo.LocalEndpoint.Address.IPAddress,
                    _netStatInfo.LocalEndpoint.Port);
                }

                return _localAddress;
            }
        }

        public string RemoteAddress {
            get
            {
                if (_remoteAddress == null)
                {
                    _remoteAddress = string.Format(
                    "{0}:{1}",
                    _netStatInfo.RemoteEndpoint.Address.IPAddress,
                    _netStatInfo.RemoteEndpoint.Port);
                }

                return _remoteAddress;
            }
        }

        public string State
        {
            get
            {
                return _netStatInfo.State;
            }
        }

        public string ProcessName
        {
            get
            {
                return _netStatInfo.ProcessName;
            }
        }
    }
}
