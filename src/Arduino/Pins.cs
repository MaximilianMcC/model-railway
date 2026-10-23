enum PinType
{
	Input,
	InputPullup,
	Output
}

enum PinValue
{
	Low = 0,
	High = 1
}

class Pin
{
	public Arduino Arduino { get; set; }
	public int Number { get; set; }

	public Pin(Arduino arduino, int number)
	{
		Arduino = arduino;
		Number = number;
	}

	private PinType type;
	public PinType Type
	{
		get => type;
		set
		{
			string mode = value switch
			{
				PinType.Input => "IN",
				PinType.InputPullup => "PULLUP",
				PinType.Output => "OUT",
				_ => Error(value)
			};

			Arduino.SendSerialCommand($"MODE {Number} {mode}");
			type = value;
		}
	}

	//? there is also a READ serial command but idk if it needs to be used. Could potentially use it to check for if the command went through but idk
	private PinValue digitalValue;
	public PinValue Value
	{
		get => digitalValue;
		set
		{
			if (value is not PinValue.High and not PinValue.Low) Error(value);
			char level = digitalValue == PinValue.High ? '1' : '0';

			Arduino.SendSerialCommand($"WRITE {Number} {level}");
			digitalValue = value;
		}
	}

	private string Error(object thing) => throw new ArgumentOutOfRangeException(nameof(thing));
}