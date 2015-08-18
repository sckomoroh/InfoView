using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.ObjectModel;

namespace WpfPluginSample.WpfPart.ViewModel
{
    public class ControlViewModel
    {
        public ControlViewModel()
        {
            Items = new ObservableCollection<ModelItem>();
        }

        public ObservableCollection<ModelItem> Items { get; set; }

        public void BuildModel(string folder)
        {
            var fileName = Path.Combine(folder, "ExecutableVersions.txt");
            var lines = File.ReadAllLines(fileName);

            foreach (var line in lines)
            {
                var index = line.IndexOf("--");
                var name = line.Substring(0, index - 1);
                var version = string.Empty;

                if (index + 3 >= line.Length)
                {
                    version = "N/A";
                }
                else
                {
                    version = line.Substring(index + 3);
                }

                Items.Add(new ModelItem
                {
                    Name = name,
                    Version = version
                });
            }
        }

        public void ResetModel()
        {
            Items.Clear();
        }
    }
}
