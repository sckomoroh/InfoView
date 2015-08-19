using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using NetStatPluginSample.WpfPart.ViewModel;

namespace NetStatPluginSample.WpfPart.View
{
    /// <summary>
    /// Interaction logic for NetStatControl.xaml
    /// </summary>
    public partial class NetStatControl : UserControl
    {
        public NetStatControl()
        {
            InitializeComponent();
        }

        public void InitPluginData(string folder)
        {
            ViewModel.BuildModel(folder);
        }

        public void ResetPluginData()
        {
            ViewModel.ResetModel();
        }

        private ControlViewModel ViewModel
        {
            get
            {
                return DataContext as ControlViewModel;
            }
        }
    }
}
