using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Windows.Forms.Integration;
using NetStatPluginSample.WpfPart.View;

namespace NetStatPluginSample
{
    [ClassInterface(ClassInterfaceType.None), Guid("FBBC0EC2-57E8-430A-80DC-B78BCED295E6")]
    [ComVisible(true)]
    [ProgId("NetStatInfo.InfoViewPlugin")]
    public class PluginControlHost : ElementHost, IPlugin
    {
        private NetStatControl _control = new NetStatControl();

        public PluginControlHost()
        {
            base.Child = _control;
        }

        public void InitPluginData(string folder)
        {
            _control.InitPluginData(folder);
        }

        public void ResetPluginData()
        {
            _control.ResetPluginData();
        }

        public string GetPluginName()
        {
            return "Net stat";
        }

        public string GetPluginId()
        {
            return "{FBBC0EC2-57E8-430A-80DC-B78BCED295E6}";
        }

        public IntPtr GetPluginIcon()
        {
            return Properties.Resources.PluginIcon.GetHbitmap();
        }
    }
}
