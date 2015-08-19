using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;

namespace NetStatPluginSample.WpfPart.ViewModel
{
    public class Address
    {
        public string Family { get; set; }

        public IPAddress IPAddress { get; set; }
    }

    public class Endpoint
    {
        public string Port { get; set; }

        public Address Address { get; set; }
    }

    public class NetStatInfo
    {
        public string ProcessId { get; set; }

        public string ProcessName { get; set; }

        public string ProtocolType { get; set; }

        public string State { get; set; }

        public Endpoint LocalEndpoint { get; set; }

        public Endpoint RemoteEndpoint { get; set; }
    }
}
