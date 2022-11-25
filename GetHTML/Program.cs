﻿using System;
using System.IO;
using System.Net;
using System.Text;

namespace test
{
    class Program
    {
        public static String GetCode(string urlAddress)
        {
            string data = "";
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(urlAddress);
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            if (response.StatusCode == HttpStatusCode.OK)
            {
                Stream receiveStream = response.GetResponseStream();
                StreamReader readStream = null;
                if (response.CharacterSet == null)
                {
                    readStream = new StreamReader(receiveStream);
                }
                else
                {
                    readStream = new StreamReader(receiveStream, Encoding.GetEncoding(response.CharacterSet));
                }
                data = readStream.ReadToEnd();
                response.Close();
                readStream.Close();
            }
            return data;
        }
        static void Main(string[] args)
        {
            string text = GetCode("https://rostov.hh.ru/");
            Console.WriteLine(text);
            string path = "web-page.html";
            File.WriteAllText(path, text);
            Console.Read();
        }
    }
}