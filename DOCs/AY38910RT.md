# How to use the PSG AY-3-8910 RT MSX SDCC Library


---
## Index
- 1 Requirements
- 2 Definitions
   - 2.1 AY Registers
   - 2.2 Envelope shapes
   - 2.3 AY channels
- 3 Functions
- 4 Set Internal or External AY
- 5 Appendices
   - 5.1 AY-3-8910 Register Table  
- 6 References
   
<br/>

---
## 1 Requirements

* Small Device C Compiler (SDCC) v4.1 > http://sdcc.sourceforge.net/
* Hex2bin v2.5 http://hex2bin.sourceforge.net/


<br/>

---
## 2 Definitions

### 2.1 AY Registers

Label | Value | Description
-- | -- | -- 
AY_ToneA     |  0 | Channel A Tone Period (12 bits)
AY_ToneB     |  2 | Channel B Tone Period (12 bits)
AY_ToneC     |  4 | Channel C Tone Period (12 bits)
AY_Noise     |  6 | Noise Period (5 bits)
AY_Mixer     |  7 | Mixer
AY_AmpA      |  8 | Channel Volume A (4 bits + B5 active Envelope)
AY_AmpB      |  9 | Channel Volume B (4 bits + B5 active Envelope)
AY_AmpC      | 10 | Channel Volume C (4 bits + B5 active Envelope)
AY_EnvPeriod | 11 | Envelope Period (16 bits)
AY_EnvShape  | 13 | Envelope Shape

<br/>

### 2.2 Envelope shapes

The header file defines envelope shapes in case you prefer to use it instead 
of the numerical form:

Label | Value
-- | --  
AY_ENV_LowerBeat     | 1 
AY_ENV_Upper         | 4 
AY_ENV_LeftSaw       | 8
AY_ENV_LowerTriangle | 10 
AY_ENV_LowerHold     | 11 
AY_ENV_RightSaw      | 12
AY_ENV_UpperHold     | 13
AY_ENV_UpperTriangle | 14

**Attention!** The LowerBeat shape may be produced with the values: 0, 1, 2, 3 and 9. 
The value 1 has been assigned to *LowerBeat* as 0 can be useful in case you need to control when the envelope is triggered. In this case 0 can act as a "don't
write the envelop" event. Remember that, every time the register 13 is written, the sound with the assigned shape is started.

The Upper shape may be produced with the values: 4, 5, 6, 7 and 15.

<br/>

### 2.3 AY channels

You can use it in the functions: SetTonePeriod, SetVolume and SetChannel

Label | Value
-- | -- 
AY_Channel_A | 0
AY_Channel_B | 1
AY_Channel_C | 2

<br/>

---  
## 3 Functions

<table>
<tr><th colspan=2 align="left">SOUND</th></tr>
<tr><td colspan="2">Write into a register of PSG</td></tr>
<tr><th>Function</th><td>SOUND(register, value)</td></tr>
<tr><th>register</th><td>[char] register number (0 to 13)</td></tr>
<tr><th>value</th><td>[char] value</td></tr>
<tr><th>Output</th><td> --- </td></tr>
<tr><th>Examples:</th><td>
<pre><code>Sound(8,16); //channel A envelope on</code></pre>
</td></tr>
</table>

<table>
<tr><th colspan=2 align="left">GetSound</th></tr>
<tr><td colspan=2>Read PSG register value</td></tr>
<tr><th>Function</th><td>GetSound(register)</td></tr>
<tr><th>register</th><td>[char] register number (0 to 13)</td></tr>
<tr><th>Output</th><td>[char] value</td></tr>
<tr><th>Examples:</th><td>
<pre><code>char value;            
value = GetSound(7);  //read mixer register</code></pre>
</td></tr>
</table>

<table>
<tr><th colspan=2 align="left">SetTonePeriod</th></tr>
<tr><td colspan=2>Set Tone Period for any channel</td></tr>
<tr><th>Function</th><td>SetTonePeriod(channel, period)</td></tr>
<tr><th>channel</th><td>[char] channel (0, 1 or 2)</td></tr>
<tr><th>period</th><td>[unsigned int] period (0 - 4095)</td></tr>
<tr><th>Output</th><td> --- </td></tr>
<tr><th>Examples:</th><td>
<pre><code>SetTonePeriod(AY_Channel_B,1100);  //set tone period for channel A</code></pre>
</td></tr>
</table>

<table>
<tr><th colspan=2 align="left">SetNoisePeriod</th></tr>
<tr><td colspan=2>Set Noise Period</td></tr>
<tr><th>Function</th><td>SetNoisePeriod(period)</td></tr>
<tr><th>period</th><td>[char] Noise period (0 - 31)</td></tr>
<tr><th>Output</th><td> --- </td></tr>
<tr><th>Examples:</th><td>
<pre><code>SetNoisePeriod(10);</code></pre>
</td></tr>
</table>

<table>
<tr><th colspan=2 align="left">SetEnvelopePeriod</th></tr>
<tr><td colspan=2>Set Envelope Period</td></tr>
<tr><th>Function</th><td>SetEnvelopePeriod(period)</td></tr>
<tr><th>period</th><td>[unsigned int] Envelope period (0 - 65535)</td></tr>
<tr><th>Output</th><td> --- </td></tr>
<tr><th>Examples:</th><td>
<pre><code>SetEnvelopePeriod(1000);</code></pre>
</td></tr>
</table>

<table>
<tr><th colspan=2 align="left">SetVolume</th></tr>
<tr><td colspan=2>Set volume channel</td></tr>
<tr><th>Function</th><td>SetVolume(channel, volume)</td></tr>
<tr><th>channel</th><td>[char] channel (0, 1 or 2)</td></tr>
<tr><th>volume</th><td>[char] volume, 0 to 15 or 16 for activate envelope</td></tr>
<tr><th>Output</th><td> --- </td></tr>
<tr><th>Examples:</th><td>
<pre><code>SetVolume(0,14);  // set 14 volume level for channel A
SetVolume(1,16);  // activate envelope for channel B</code></pre>
</td></tr>
</table>

<table>
<tr><th colspan=2 align="left">SetChannel</th></tr>
<tr><td colspan=2>Mixer. Enable/disable Tone and Noise channels.</td></tr>
<tr><th>Function</th><td>SetChannel(channel, isTone, isNoise)</td></tr>
<tr><th>channel</th><td>[char] channel (0, 1 or 2)</td></tr>
<tr><th>isTone</th><td>[boolean] Tone channel state</td></tr>
<tr><th>isNoise</th><td  width=300>[boolean] Noise channel state</td></tr>
<tr><th>Output</th><td> --- </td></tr>
<tr><th>Examples:</th><td>
<pre><code>SetChannel(0,true,false);
SetChannel(1,true,true);
SetChannel(2,false,false);</code></pre>
</td></tr>
</table>

<table>
<tr><th colspan=2 align="left">PlayEnvelope</th></tr>
<tr><td colspan=2>Set envelope type.<br/>Plays the sound on channels that have a volume of 16.</td></tr>
<tr><th>Function</th><td>PlayEnvelope(shape)</td></tr>
<tr><th>shape</th><td>[char] Envelope shape (0-15)</td></tr>
<tr><th>Output</th><td> --- </td></tr>
<tr><th>Examples:</th><td>
<pre><code>PlayEnvelope(0); //Play LowerBeat envelope shape
<br/>           
PlayEnvelope(ENV_LowerTriangle); //Play LowerTriangle envelope shape</code></pre>
</td></tr>
</table>

<br/> 

---
## 4 Set Internal or External AY

To indicate in which PSG the sounds are to be played, you have the **isAYextern** variable. 
To select an external AY, like the one included in the MegaFlashROM SCC+ (ports 10h to 12h), you have to set the variable to true (or 1).

```
  isAYextern = true;
```

The library does not contain an initialization function so it is recommended to provide a value to this variable at the beginning of your program.

<br/>

---
## 5 Appendices


### 5.1 AY-3-8910 Register Table

<table>
<tr>
<th colspan=2>Register\bit</th><th width=50>B7</th><th width=50>B6</th><th width=50>B5</th><th width=50>B4</th><th width=50>B3</th><th width=50>B2</th><th width=50>B1</th><th width=50>B0</th>
</tr>
<tr>
<td>R0</td><td rowspan=2>Channel A Tone Period</td><td colspan=8 align="center">8-Bit Fine Tune A</td>
</tr>
<tr>
<td>R1</td><td colspan=4></td><td colspan=4 align="center">4-Bit Coarse Tune A</td>
</tr>
<tr>
<td>R2</td><td rowspan=2>Channel B Tone Period</td><td colspan=8 align=center>8-Bit Fine Tune B</td>
</tr>
<tr>
<td>R3</td><td colspan=4></td><td colspan=4 align="center">4-Bit Coarse Tune B</td>
</tr>
<tr>
<td>R4</td><td rowspan=2>Channel C Tone Period</td><td colspan=8 align=center>8-Bit Fine Tune C</td>
</tr>
<tr>
<td>R5</td><td colspan=4></td><td colspan=4 align="center">4-Bit Coarse Tune C</td>
</tr>
<tr>
<td>R6</td><td>Noise period</td><td colspan=3></td><td colspan=5 align=center>5-Bit Period control</td>
</tr>
<tr>
<td rowspan=2>R7</td><td rowspan=2>Enable (bit 0=on, 1=off)</td><td colspan=2 align="center">IN/OUT</td><td colspan=3 align="center">Noise</td><td colspan=3 align="center">Tone</td></tr>
<tr>
<td align=center> IOB</td><td align="center">IOA</td><td align="center">C</td>
<td align=center>B</td><td align="center">A</td><td align="center">C</td>
<td align=center>B</td><td align="center">A</td>
</tr>
<tr>
<td>R8</td><td>Channel A Amplitude</td><td colspan=2></td><td align="center">Env</td><td colspan=5 align="center">Amplitude</td>
</tr>
<tr>
<td>R9</td><td>Channel B Amplitude</td><td colspan=2></td><td align="center">Env</td><td colspan=5 align="center">Amplitude</td>
</tr>
<tr>
<td>R10</td><td>Channel C Amplitude</td><td colspan=2></td><td align="center">Env</td><td colspan=5 align="center">Amplitude</td>
</tr>
<tr>
<td>R11</td><td rowspan=2>Envelope Period</td><td colspan=8 align="center">8-Bit Fine Tune Envelope</td>
</tr>
<tr>
<td>R12</td><td colspan=8 align="center">8-Bit Coarse Tune Envelope</td>
</tr>
<tr>
<td>R13</td><td>Envelope Shape/Cycle</td><td colspan=4></td><td>CONT</td><td>ATT</td><td>ALT</td><td>HOLD</td>
</tr>
<tr>
<td>R14</td><td>I/O Port A Data Store</td><td colspan=8 align="center">8-Bit Parallel I/O on Port A</td>
</tr>
<tr>
<td>R15</td><td>I/O Port B Data Store</td><td colspan=8 align="center">8-Bit Parallel I/O on Port B</td>
</tr>
</table>



<br/>

---
## 6 References

* [General Instrument AY-3-8910 (wikipedia)](https://en.wikipedia.org/wiki/General_Instrument_AY-3-8910)
* [GI AY-3-8910 Datasheet (PDF)](http://map.grauw.nl/resources/sound/generalinstrument_ay-3-8910.pdf)
