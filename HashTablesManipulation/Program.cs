using System;
using System.Collections;
using System.Collections.Generic;
using System.IO.Pipes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    { /*
        static void AddInHash(Hashtable ht, string fst, string scd)
        {
            if (ht.Contains(fst) == true)
            {
                ht.Add(fst.Substring(0, 1), scd);
            }
            else
            {
                ht.Add(fst, scd);
            }
        }
        */
        static void Main(string[] args)
        {
            Hashtable ht = new Hashtable();
            do
            {

            Remake:
                Console.Write("Введите ключ, который будет у элемента в таблице: ");
                string answer_one = Console.ReadLine();
                Console.WriteLine();
                Console.Write("Введите элемент, который нужно добавить в таблицу: ");
                string answer_two = Console.ReadLine();
            JustKey:
                try
                {
                    ht.Add(answer_one, answer_two);
                }
                catch
                {
                    Console.WriteLine("Похоже, что элемент с таким ключом уже существует.\n1 - Ввести другой ключ\n2 - Ввести другой ключ и значение\n3 - Не хочу ничего добавлять");
                    int oneOfThree = int.Parse(Console.ReadLine());
                    if (oneOfThree == 1)
                    {
                        Console.Write("Введите ключ, который будет у элемента в таблице: ");
                        answer_one = Console.ReadLine();
                        goto JustKey;
                    }
                    else if (oneOfThree == 2)
                    {
                        goto Remake;
                    }
                }
                
                ICollection keys = ht.Keys;

                foreach (string s in keys)
                    Console.WriteLine(s + ": " + ht[s]);

                Console.WriteLine("Искать элемент по ключу или значению?\n1 - Ключ\n2 - Значение");
                int answer = int.Parse(Console.ReadLine());
                if (answer == 1)
                {
                    Console.WriteLine("Введите ключ:");
                    string answer_search = Console.ReadLine();
                    if (ht.ContainsKey(answer_search) == true)
                    {
                        Console.Write("Элемент с таким ключом есть в таблице и имеет следующее значение: ");
                        Console.WriteLine(ht[answer_search]);
                    }
                    else
                    {
                        Console.WriteLine("Элемента с таким элементом не существует");
                    }
                }
                else if (answer == 2) 
                {
                    Console.WriteLine("Введите значение:");
                    string answer_search = Console.ReadLine();
                    if (ht.ContainsValue(answer_search) == true)
                    {
                        Console.WriteLine("Элемент с таким значением есть в таблице и имеет следующий(-ие) ключ(-и): ");
                        foreach (string s in keys)
                        {
                            if (ht[s].Equals(answer_search))
                                Console.WriteLine(s);
                        }                          
                    }
                    else
                    {
                        Console.WriteLine("Элемента с таким значением не существует");
                    }
                }
            } while (true);
        }
    }
}
