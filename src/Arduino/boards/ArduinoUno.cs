class ArduinoUno : Arduino
{
	public ArduinoUno(string portName, int baudRate = 115200) : base(portName, baudRate) { }

	public Pin Led => pins[13];

	protected override void SetupPins()
	{
		// 0 - 14 are digital pins
		for (int i = 0; i <= 14; i++)
		{
			pins.Add(i, new Pin(this, i));
		}
	}
}