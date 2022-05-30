using System;
using System.Collections.Generic;

namespace EntityFramework
{
    public partial class Product
    {
        public int Id { get; set; }
        public string Name { get; set; } = null!;
        public string Type { get; set; } = null!;
    }
}
