using System.IO.Ports;

class Program
{
	public static void Main(string[] args)
	{
		ArduinoUno arduino = new ArduinoUno("COM3");
		Pin led = arduino.Led;

		while (true)
		{
			Console.ReadKey();
			led.Value = PinValue.High;
			Console.ReadKey();
			led.Value = PinValue.Low;
		}
	}
}