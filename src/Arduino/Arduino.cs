using System.IO.Ports;

//! this whole thing is blocking because of the thread sleeps
abstract class Arduino
{
	public string PortName => connection.PortName;
	public int BaudRate => connection.BaudRate;

	protected readonly Dictionary<int, Pin> pins = [];
	public IReadOnlyDictionary<int, Pin> Pins => pins;

	protected SerialPort connection;

	public Arduino(string portName, int baudRate = 115200)
	{
		// Connect to the arduino
		connection = new SerialPort(portName, baudRate)
		{
			NewLine = "\n",
			ReadTimeout = 2000,
			WriteTimeout = 2000
		};
		connection.Open();

		// Wait a sec for it to actually turn on
		Thread.Sleep(2000);
		connection.DiscardInBuffer();

		// Send a ping to check if its working
		if (Ping() == false)
		{
			Console.WriteLine("Connection failed (ping didn't work)");
			return;
		}

		// Set the pins (board specific)
		SetupPins();
	}

	protected abstract void SetupPins();

	public string SendSerialCommand(string command)
	{
		connection.WriteLine(command);
		return connection.ReadLine().Trim();
	}

	public bool Ping() => SendSerialCommand("PING") == "PONG";
}