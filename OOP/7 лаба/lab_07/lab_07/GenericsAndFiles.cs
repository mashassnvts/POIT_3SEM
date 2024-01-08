using System.Text.Json;
using System.Xml;

namespace lab_07
{
    public static class GenericsAndFiles
    {
        public static void WriteList<T>(List<T> list)
        {
            JsonSerializer serializer = new JsonSerializer();
            serializer.NullValueHandling = NullValueHandling.Ignore;

            using (StreamWriter sw = new StreamWriter(@"D:\3 семестр\OOP\7 лаба\lab_07\lab_07\Data.json"))
            using (JsonWriter writer = new JsonTextWriter(sw))
            {
                writer.Formatting = Formatting.Indented;
                serializer.Serialize(writer, list.Head);
            }
        }
        public static void ReadList<T>(List<T> list)
        {
            var settings = new JsonSerializerSettings
            {
                TypeNameHandling = TypeNameHandling.All,
            };
            using var stream = new StreamReader(@"D:\3 семестр\OOP\7 лаба\lab_07\lab_07\Data.json");
            string JsonData = stream.ReadToEnd();

            List<T>.Node Head = JsonConvert.DeserializeObject<List<T>.Node>(JsonData, settings);
            List<T>.Node current = Head;
            while (current.Next != null)
            {
                list.Add(current.Data);
                current = current.Next;
            }
        }
    }
}
