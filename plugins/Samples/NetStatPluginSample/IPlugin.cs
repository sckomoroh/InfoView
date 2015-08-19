using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace NetStatPluginSample
{
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [Guid("FCCF02DE-3FC1-4687-A978-072F0C388B0B")]
    [ComVisible(true)]
    public interface IPlugin
    {
        void InitPluginData(string name);
        void ResetPluginData();
        string GetPluginName();
        string GetPluginId();
        IntPtr GetPluginIcon();
    }
}
