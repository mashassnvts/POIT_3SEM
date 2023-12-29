using lab_04;
using System;

namespace lab_04
{
    class Printer
    {
        public void IAmPrinting(Inventory inventory)
        {
            Console.WriteLine(inventory.ToString());
        }
    }
}