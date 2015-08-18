using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Windows.Forms.Integration;
using WpfPluginSample.WpfPart.View;

namespace WpfPluginSample
{
    [ClassInterface(ClassInterfaceType.None), Guid("7B85D508-D4A7-4D24-9D5C-3680408DDA7E")]
    [ComVisible(true)]
    [ProgId("VersionInfo.InfoViewPlugin")]
    public class PluginControlHost : ElementHost, IPlugin
    {
        private ExecVerPluginSample _control = new ExecVerPluginSample();

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
            return "Executable versions";
        }

        public string GetPluginId()
        {
            return "{7B85D508-D4A7-4D24-9D5C-3680408DDA7E}";
        }

        public IntPtr GetPluginIcon()
        {
            return Properties.Resources.PluginIcon.GetHbitmap();
        }
    }
}
