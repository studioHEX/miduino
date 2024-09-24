# miduino
Miduino is a solution for connecting Arduino to Ableton
<img width="970" alt="Screenshot 2024-09-23 at 21 44 39" src="https://github.com/user-attachments/assets/a3674456-1f75-4cd1-b3fd-2782948b598f">

Through my employment at art Academy Minerva I get a lot of students looking to sonify data in one way or anouther. Often whenever they have been 
introduced to Arduino they seek a way to sonify the sensor data. Usually I introduce them to MAX/MSP or PureData because it is easy to
get the values in and connect them to an oscillator of some sorts. However, the student often doesn't seek to understand synthesis or how
to model complex sounds from scratch. They want to play around with instruments, filters and effects to create a sonically tapestry fitting
to their concept. And want sensors to be in charge. 

Either building a theremin with greatly enhanced sonic possibilities through distance sensors.
Making plants talk through ECG sensor data.
Have some death metal rock out on the collected water levels of your daisies.

It doesn't matter what you want, with Miduino and the Miduino_client you can! My aim was to make the transfer from Arduino to Ableton easy and
foolproof. No more patching for the students if they don't want to. No more devices that seem not to work, just a ready out of the box device.

Miduino itself acts like a host for the Arduino inside Ableton and can receive up to 13 sensorical values sent through Serial. Miduino
distributes that over the device having a channel for each incoming value. The values can be interpreted RAW into MIDI for the loaded track or they
can be recalculated into the full MIDI range. This recalculation happens on the background and is looking constantly for the lowest and highest RAW
sensor value to rescale the range to the MIDI range. The user only needs to tick a toggle between raw or calculated.

The tempo of letting values through can also be adjusted and works on milliseconds. Through this option you can have channels of values triggering notes on different intervals. Allowing you to not have to deal with delay(); or millis(); in arduino but simply increasing or decreasing the tempo numberbox.

There is a manual control for note length allowing either very short notes or have drones being active that go on for about a minute. Also this value goes in milliseconds. Additionally you can activate swing and/or shift to organically vary in velocity and duration. 

Then there is macro control to allow additional control through sensor value throughout your Ableton Live set. Macro control allows you to map the dial to other dials and have it control it. The macro control comes with a min/max range number box so you can finetune the range of the mapped parameter. Macro was chosen here instead of MIDI CC due to limitations or a bug in Max4Live not allowing MIDI CC from a Max4Live-device because Ableton is looking for an external MIDI controller. The macro control can only happen on the track it is loaded onto as is the MIDI control.


<img width="227" alt="Screenshot 2024-09-23 at 22 10 08" src="https://github.com/user-attachments/assets/505db760-f155-46c2-a8c4-389fb55e546d">

Introducing the Miduino_client, a small device that takes the values from Miduino into a single channel. Through these clients you can distribute the same channel onto different tracks. Have them trigger different MIDI instruments or have them control parameters through macro control. The values between Miduino and Miduino_client are passed through OSC running on 127.0.0.1 localhost ip address and each channel in Miduino sends to its own port, which can be selected easily through a dropdown menu. You can load multiple clients onto the same track with different OSC ports having them do different things. 

Oh the possibilities are endless!

The Arduino side of things are not very special in the ways of you having to do elaborate set-up. The only thing that is important
is the way of formatting the serial output from Arduino to your computer.

You can find an example Arduino sketch in the files directory of this repo. Simply put you have to print out all the values on the same line with a space separating them and 
closing off with an end-of-line-character. Which can either be '\n' or println();

If the sensor data is not output like this then Miduino will not be able to parse the data correctly and error might occur.

I sincerely hope this will make the life of people easier so we can focus more on creating and improving our workflows. 

Bug report:
*Macro not working : fixed
*Serial error between Windows/MAC : fixed
*MIDI not passed through Miduino_client : fixed
*Small change in GUI Miduino to increase readability

