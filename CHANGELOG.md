Firmware for HX3.6/HX3.7 boards only. **Do not use on HX3.5 devices!** Please see the [**HX3.6 Migration Guide (english)**](https://wiki.keyboardpartner.de/index.php?title=HX3.6_Migration_Guide_(english)) resp.
[**HX3.6 Migration Guide (deutsch)**](https://wiki.keyboardpartner.de/index.php?title=HX3.6_Migration_Guide_(deutsch)). 

**Note:** This firmware is compatible with HX3.6 boards; however, menu for external effect insert does nothing on HX3.6.

#### Update Parts/Files Version List

| File/Part       | Version in Update #7.063 |
|-----------------|--------------------------|
|=================|======================    |
| Manager:        | **#7.23**                |
| FPGA:           | **#24022026**            |
| Firmware:       | **#7.064**               |
| DSP:            | **#x1.26**    |
| Defaults:       | -                        |
| Presets:        | -                        |
| MIDI CCs:       | (ccset8.dat)           |
| Scan Driver     | **#6x.52**                |
| Taperings       | -                        |
| Wavesets:       | -                        |
| Organ Models:   | (organs.dat)       |
| Speaker Models: | (speakers.dat)     |
| Bootloader:     | (required: #1.05)      |

### **22.02.2026** Manager #7.23, Firmware #7.064, Scan Drivers #6x.52, FPGA #24022026 BETA (but likely final)

* Scan Drivers: New types for Pulse 6105W and FatarScan1-61 (future products)
* Scan Drivers (all Fatar, Pulse and XB2/XB5): Improved dynamic curves for key velocity using a pre-loaded velocity curve
* FPGA: Added RAM for loadable velocity curves
* Firmware: Support for loadable velocity curves, better dynamic resolution
* HX3 Manager: Support for new scan drivers, Pulse 6105W, FatarScan1-61, FatarScan1-73 (future products)

**Note:** Scan drivers for velocity-sensitive keyboards (XB2/XB5, Fatar and Pulse) got a major update and are **no longer compatible with HX3.5** due to lack of velocity RAM. The old 1/t emulation was insufficient in scan driver. Instead, a 256-step dynamic curve is now computed by main MCU and uploaded to FPGA. The curve slope is still adjusted by param #1363. Be sure to update scan driver along with FPGA when using a XB2 or Fatar keybed!

#### **22.02.2026** MIDI Scan Driver #63.51 BETA

* **Bugfix:** Forgot to publish new MIDI scan driver, old version #63.50 from Jan 6th did not trigger percussion

#### **25.01.2026** Manager #7.22, Firmware #7.063, Scan Driver #63.50, DSP #x1.26 BETA

* HX3 Manager/Bootload Utility: **Bugfix,** DFU upload tools did not start properly (required admin rights)
* HX3 Manager/CC Set Editor: New Value Mode 10, will switch a tab if *min* and *max* values are exactly met
* HX3 Manager/Update Finalizer: added support for future FatarScan61 board (scan board for single Fatar keybeds)
* Firmware: Improved CC handling, same MIDI CCs may be assigned multiple times without restrictions to control more than one parameter/tab at the same time, support for Value Mode 10
* Firmware: **Bugfix,** secondary drawbar set selection did not work (only applies for organs with 2 drawbar sets per manual using DBX drawbar boards)
* Firmware: Reverb enabled on plain Organ Main and 11-pin output when EFX disabled
* Firmware: Added support for PresetIndicator and FatarScan61 (new products)
* Scan Driver MIDI: **Bugfix,** lower manual did not work at all on #63.49 MIDI Scan Driver
* Scan Driver FT61: New version *scanft61.dat* for future FatarScan61 board
* DSP: Reverb enabled on plain Organ Main output

**Note:** Also see remarks for Firmware #7.060 when updating from older 
versions. **Do not use** defective Fatar Scan Driver #61.49 from Jan 6, 2025, 
it has been fixed on Jan 8th. 

Reverb on plain *Organ Main* output had been disabled in prior firmware versions 
to prevent feedback through reverb DSP. With updated DSP (#x1.26) and new 
firmware, reverb and equalizer are available on *Main* (resp. 11-pin Leslie) 
output when external FX loop is disabled. With active FX loop, reverb and 
equalizer on *Main* output are both disabled to prevent double equalizing and 
reverb feedback.

A bug in HX3 Manager (introduced recently) was fixed which leads to multiple 
dialogs (dependant on Windows user account settings) when executing 
DFU/bootloader utils (which inadvertedly required admin user rights). This was a 
nasty one which may have prevented updates at all.

Firmware got a new CC handling with faster response times. Now it is possible to 
assign the same *Channel/CC* number to multiple random parameters without 
restrictions for improved flexibility (like value dependant control of vibrato 
rotary switch). Also, there is a new *Value Mode* #10 which will switch a tab 
(or any digital function) to OFF if MIDI value = *min* and switch to ON if value 
= *max*. In *Value Mode* #10, *max* may be smaller than *min* to get an inverted 
behaviour; it will respond to exact matches only.

#### **11.12.2025** Manager #7.21, Firmware #7.060, FPGA #11122025, Organ Models, Speaker Models, Scan Driver #6x.49 (MIDI, Fatar) BETA!

This is a beta release for evaluation with **major changes**. Firmware may change in next few days without version 
number change - please compare release date. 

* Firmware: **Bugfix,** HX3 sometimes did not recognize SD cards when inserted while running
* Firmware: Change in param #1387, now also "TG Taper Multiplier Adjust" (nominal value = 32..40) for tonewheel organs
* Firmware: Will start up with upper and lower voice (drawbar) preset from param #1504 (first drawbar set, nominal "0"), 
so design of "inverted keys" preset boards is more flexible (highest "B" key may be voice preset 11)
* FPGA: Updated biquad filter, higher output level on rotary simulation outputs and higher vibrato dynamic range
* FPGA: Added dithering in vibrato scanner circuit to prevent "ticker" noise
* FPGA: New AO28 filter structure with improved response
* FPGA: Built-in sine sweep generator for testing purposes
* FPGA: Additional MIDI FIFO for MIDI USB, both MIDI DIN inputs **and MIDI USB** may be used at the same time now (will merge MIDI data)
* Editor: New Sweep Generator
* Editor: Trackbar behaviour changed, did not send values on up/down click
* Editor: Removed obsolete params
* Scan Driver (MIDI, Fatar): Support for new FPGA with MIDI USB FIFO, implemented a separate MIDI USB receiver

**Note:** The HX3 Sound engine got a completely revised AO28 simulation with improved filters and new parameters. 
This firmware no longer supports 3 swell pedal models (old param #1384 in *Organ Setup*), instead there are 5 new params in volume control:

* **1091 (nom. =90)** AO28 Swell Loudness Bass - controls loudness bass boost (on low swell pedal)
* **1092 (nom. =40)** AO28 Swell Midrange Response - controls midrange lowpass frequency cutoff (-3dB point)
* **1093 (nom. =25)** AO28 Swell Midrange Shelving - controls midrange slope (dB/Oct cutoff slope)
* **1094 (nom. =40)** AO28 Swell Final Response - controls final low pass filter (overall response, > 4kHz range
* **1095 (nom. =35)** AO28 Swell Loudness Treble - controls loudness treble boost (on low swell pedal)

As these params are saved along with organ model, it is possible to create highly customized swell response curves for **each organ model**,
even with zero volume possible on minimal swell (B3 organ has a swell pedal with loudness corrected volume on minimal position). 
As an option, there is a new built-in sweep generator (tab **Swell Sweep**) which generates sweeps for comprehensive test of swell pedal frequency 
responses as well as external FX devices or even real organ preamps (like AO28 in B3 organ). Contact us for a licence code. 
Without licence, you may use the test generator, but you cannot record sweeps. 
See https://wiki.keyboardpartner.de/index.php?title=HX3_Sweep_Generator for details on sweep generator.

Param #1387 "TG Fixed Taper Value" is now also an adjustment for tapering of tonewheel organ models. Values greater than 32 will increase overall taper 
level, values lower than 32 will decrease it. In the past it was used only as a fixed taper value for non-tonewheel organs. 
Adjust #1387 for equal loudness of organ models and good tube amp overdrive. Note that too high levels will cause distortions in vibrato circuit.
We fixed the crossover circuit (biquad filter) which was too lossy, so overall output level is now somewhat higher.

This update needs **new organ/speaker models** and **new scan driver** to work properly. If you want to use your existing organ and speaker models, 
be sure to set param values #1091 to #1095 according to nominal values as in table shown, also an adjustment of #2104 Rotary Input Level may be necessary
in order to account for the higher biquad crossover output levels.

#### **16.11.2025** Firmware #7.053

* Firmware: **Bugfix,** menu item "ContEarlyActn" (use early key contact on Fatar keybeds) did not appear in TG submenu; please note that this submenu only works with FatarScan driver
* Firmware: **Bugfix,** some menu groups too long and inconsistent
* Firmware: Added menu item "SMask" (Preset Save Enable Mask) in main submenu, determines which settings are saved/recalled from Common Preset

**Note:** This new menu makes "Save Enable Mask" (as by param #1498 or Preset Enable checkboxes in HX3 Manager/Panel) available by menu system. To make changes permanent, use 
adjacent submenu "Save Defaults". Also note that most menu enables (params #6000 ff.) have moved one position upwards due to new menu entry.

|Bit|SubMenu|Saved Preset Item when ON|
|----|---------|-----------------------| 
|====|=========|=======================|
|0 |UpperDB |Upper DBs|
|1 |LowerDB |Lower DBs|
|2 |PedalDB |Pedal DBs|
|3 |EG,ADSR |EG Perc/ADSR Drawbars|
|4 |Tabs,Knb|Tabs/Knobs/OrganModel/RotaryModel|
|5 |S/F,Amp |Rotary Slow/Fast/Run, TubeAmp Gain|
|6 |Volumes |Volumes/Equalizer/TrimPots|
|7 |GMSynth |GM Synth|


#### **23.10.2025** Manager #7.20, Firmware #7.050, Organ Models

* Firmware: **Bugfix,** menu item "No DB1 @Perc" (disable 1' drawbar when percussion on) did not appear in organ submenu
* Firmware: Added support for new Halfmoon Switch assembly, works independently from footswitch or panel buttons
* Firmware: Added support for new MiniSwitch board with 8 switch inputs
* Firmware: Added support for OEM preamp control with MiniSwitch or Legacy Board
* Manager: Added support for MiniSwitch boards, MiniSwitch assignments
* Organ Models: Changed some vibrato params slightly to prevent ticker noise from vibrato scanner circuit

#### **16.08.2025** Manager #7.19, Firmware #7.049

* Firmware: **Bugfix,** after MIDI Expression has been received, swell value did not change back to directly connected expression pedal
* Manager: Hourglass/Wait cursor while DFU uploads, compatibility issue with Windows 11

#### **16.07.2025** Manager #7.17, Firmware #7.048, Fatar Scan Driver #61.47

* Manager/Updater: Replaced obsolete device item "Drawbar Expander" with "MIDI Expander Pro"
* Firmware: Support for older DB9-MPX drawbar boards on Legacy Board (switched A/B drawbar sets)
* Firmware: Fixed compatibility issues with HX3.6 boards. Version #7.048 may be used on HX3.6 boards without restrictions.
* Scan Driver: Improved key dynamic resolution (Fatar Scan Driver only), fixed "sometimes a missing note on GM Synth" bug

**Note:** Tweaking of parameter #1363 may be necessary to obtain optimal results 
on key dynamic range (GM Synth, MIDI output). **Due to a glitch in ZIPping the 
files, an old FPGA version was supplied prior to July 22nd. Please download ZIP again.**

#### **04.06.2025** Manager #7.16, DSP Firmware #x1.25

* Manager/CC Set Editor: Added entry for external FX insert in Tab group 5 (Expander Pro)
* DSP Firmware: **Bugfix**, reverb output no longer routed to plain organ out (feedback problem)
* DSP Firmware: Will identify as "HX3 Sound Engine" in Windows Device Manager (was "HX3.5" even on HX3.7 boards before)

**Note:** To update DSP firmware, set board to BL mode and use "Single DFU File" 
update button in HX3 Manager's **BootLoad** utility. Open "dsp_fw.dfu" resp. "dsp_fw_NoGM.dfu" 
file.

#### **19.03.2025** Firmware #7.047, FPGA #10022025

* Firmware/FPGA: Adjustable LED brightness for MIDI/Pro Expander, small bug in LED driver fixed
* Manager/CC Set Editor: Removed restrictions for CC Set DAT and CSV file names
* Manager: Open/Save dialogs streamlined
* FPGA: Support for external FX insert and Plexi Expander LED dimming

#### **30.12.2024** Firmware #7.045

* Firmware: Effect Loop Insert provision for HX3.7 board
* Organ Models: Less manual output levels to prevent Rotary Sim crossover distortions
* Speaker Models: Less input levels to prevent Rotary Sim distortions on some speaker models

#### **23.09.2024** Firmware #6.044

* Firmware: Drawbars moved slowly did not always return to zero when pushed fully in

#### **23.07.2024** Firmware #6.043, Fatar Scan Driver #61.46

* Firmware: **Bugfix**, Rotary params not saved when changed by MenuPanel
* Firmware/Editor: Misleading name "Local Enable" of parameter #1373 changed to "MIDI Send Enables" resp. "MIDI Send" in MenuPanel
* Scan Driver (Fatar): **Bugfix**, MIDI Send Enables parameter did not work

#### **31.06.2024** Firmware #6.042, FPGA #25062024, Scan Driver #6x.45

* Firmware, Editor: Support for new *Organ Models* parameter #1364, controls noisy "old/dry" (#1364=OFF) or quieter "new/lubed" (ON) mechanical key contacts
* Firmware, Editor: Support for new *Organ Models* parameter #1365, controls generator "loudness robbing" behaviour
* FPGA: Support for new/lubed contacts with elaborate contact resistance levels
* FPGA: More "compression" effect due to decreasing busbar and matching transformer load impedance when multiple notes played
* FPGA: New, more authentic approach for tone generator "loudness robbing" (drop 
  of note volume when TG wheel is accessed by multiple notes played) and "level 
  pumping/compression" (loss of drawbar volume when multiple notes played)
* Scan driver: Will produce a more authentic key-on- and key-off-click with different contact resistance levels applied

**Note:** Hammond organs with well-maintained (lubed) key contacts as well as newer 
Hammond keybed variants yield a somewhat **lower key click volume**. If a too 
loud key click is observed, update to newest firmware, FPGA and scan driver. 

*Organ Models* parameter #1365 switches compression and loudness robbing effect 
on or off. It should be ON for all tonewheel organ models.

File *Organ Models* should be updated as well. If you wish to keep your existing 
(modified or custom) organ models, set parameters #1364 and #1365 to ON or OFF in HX3 
Editor's *Organ Models* tab. Adjust *Contact Spring Flex* #1360 and *Contact 
Spring Damping* #1361 to personal taste. Click **Store as Organ Model** when done. 

New HX3.6 scan drivers **will no longer work** on HX3.5, so they have been 
renamed to **numbering scheme #6x.xx**. Please use new scan driver(s) #6x.45 
supplied in ZIP. Be sure to select the appropriate scan driver (Fatar, MIDI 
etc.) in *HX3 BootLoad* utility or *HX3 Updater*.

#### **10.04.2024** Firmware #6.040, Scan Driver #5x.44

* Firmware: Somewhat improved frequency response for B3 swell type 
* Firmware: Added Bit 6 "Separate Main/Pedal if RotaryBypass ON" in *System Inits* #1502, "Various 
Configurations 2" for separate plain organ/pedal outputs on mainboard jacks
* Firmware: Upper/Lower/Pedal Enables #1397..#1399 now part of presets (tab setting)
* Alternative scan driver with lower click noise volume ("lubed" contacts) available in separate ZIP file *scan_44.ZIP*

**Note:** It was not possible to get **separate** plain organ and pedal audio on 
main audio output jacks; when the RotaryBypass tab is ON, both organ and pedal audio are 
downmixed to mono on both Main L and R. This might be undesirable for customers 
**without** optional Extension Board when using an external rotary speaker.

When activated (checked), the new "Separate Main/Pedal if RotaryBypass ON" bit (in 
*System Inits*, parameter #1502) routes the plain organ and pedal audio separately to the 
mainboard L/R output channels when rotary/speaker simulation is bypassed. This bit should be 
OFF (unchecked) when an Extension Board is used as here both signals are present anyway.

#### **09.04.2024** Firmware #6.039

* Firmware: Different dry/wet mixture approach for reverb. Params #1400..1402 now control dry/wet mixture, while analog control "Overall Reverb" #1086 controls mainly reverb time

**Note:** Some customers noted a "thin" reverb along with lower "Overall Reverb" #1086 
values. In the past, parameter #1086 also controlled wet/dry mixture, which was undesirable. I 
changed behaviour to reverb time control on "Overall Reverb" #1086 parameter, 
while reverb "wet" levels are solely set by params #1400..1402. Max. reverb time 
(i.e. "Overall Reverb" #1086 potentiometer range) for each of the 3 reverb program (2 
buttons) is still to be set by ''DSP Setup'' params #2005..#2007.

#### **22.01.2024** FPGA #22012024

* FPGA/SoundEngine: Made some changes in rotary horn simulation to defeat artefacts on higher notes

#### **09.01.2024** Firmware #6.038

* Firmware/Editor: Added *System Inits* parameter #1502 *Various Configurations 2* bit 5 for swapping SLOW/FAST switch inputs (allows connection of Hammond halfmoon switches)

#### **22.12.2023** Firmware #6.037, FPGA #16122023 or #17122023

* Firmware: Split On/Off, Split Point and Split Mode added as saved preset parameter (saving *Tabs* enabled)
* FPGA/SoundEngine: Two versions #16122023 and #17122023 added to try out, with different bass reflex "holes" for rotor speaker 

**Note:** I'm not quite shure which FPGA/SoundEngine sounds best in respect off 
bass response. *fpgamain.bin* is version #10122023 with old bass response. I 
added two versions simulating different bass reflex "holes" to try out: #16122023 
(*fpgamain_16.bin*, 120 Hz reflex hole) and #17122023 (*fpgamain_17.bin*, 60 Hz 
reflex hole), both in *updates* directory. Please tell me your opinion.

#### **06.12.2023** Firmware #6.035, FPGA #10122023, Bootloader #1.07

* Firmware: Bugfix, digital inputs configured as switches were not read properly on startup
* Firmware: Removed "blinking LEDs on invalidated preset" feature
* FPGA: Removed diffusor from rotary horn main beam, less diffsor modulation to prevent "swirling" and grinding artefacts
* Bootloader: Support for slower SD Cards, Bootloader shuts down FPGA while loading files from SD to prevent corrupted images

**Note:** For Bootloader update to #1.07, board must be sent to KeyboardPartner for factory update (in case your SD Cards do not work properly).

#### **03.11.2023** Manager #6.11, Firmware #6.034

* Firmware: Bugfix, saving voice presets with CANCEL key did not work properly
* Manager/Editor: Added *System Inits* #1502 Various Configurations 2, Bit 4: Delayed Save with CANCEL key
* Manager/Editor: Parameter group will be refreshed to update descriptions after pop-up menu "Set subsequent Values..." is executed 

**Note:** When preset key inputs are configured as switches, HX3 will change preset 
or voice directly when "inverted" preset key is pressed, not on preset key 
release. This may also be appropriate with non-latching keys. A voice or preset 
is immediately saved by pressing the CANCEL key and then the desired save destination key. 

If bit 4 of param #1502 Various Configurations 2 is set, you must hold CANCEL key
for about 2 seconds and then the desired save destination key. This would 
prevent an unintended save of a voice or preset.

#### **03.11.2023** Manager #6.10, Firmware #6.033

* Firmware: Bugfix, MIDI CC Special Function #1674 did not handle Percussion and 1' disable properly
* Firmware: Added *Program Change Disable* submenu ("No ProgChgRcv") to MIDI menu - if ON, HX3 will not respond to MIDI program changes
* Firmware: Master Volume, Reverb Level and Tube Amp Gain saved to Preset when enabled in *System Inits*
* Firmware: Tube Amp Gain will be restored fom Preset when bit 5 of *Common Preset Save/Restore Mask* bits (System Inits #1498) is set
* Firmware: Corrected display of Save Destination in menu depending on *Common Preset Save/Restore Mask* bits (System Inits #1498)
* Firmware: Limited MIDI swell sending to 8ms cycle; heavy use of swell pedal did clog MIDI transmissions
* Manager: Added *Program Change Disable* Parameter *MIDI Setup* #1376

For changelog of older versions, see **HX3.6 Manager Current Firmware** directory. external FX insert in Tab group 5 (Expander Pro)
* DSP Firmware: **Bugfix**, reverb output no longer routed to plain organ out (feedback problem)
* DSP Firmware: Will identify as "HX3 Sound Engine" in Windows Device Manager (was "HX3.5" even on HX3.7 boards before)

**Note:** To update DSP firmware, set board to BL mode and use "Single DFU File" 
update button in HX3 Manager's **BootLoad** utility. Open "dsp_fw.dfu" resp. "dsp_fw_NoGM.dfu" 
file.

#### **19.03.2025** Firmware #7.047, FPGA #10022025

* Firmware/FPGA: Adjustable LED brightness for MIDI/Pro Expander, small bug in LED driver fixed
* Manager/CC Set Editor: Removed restrictions for CC Set DAT and CSV file names
* Manager: Open/Save dialogs streamlined
* FPGA: Support for external FX insert and Plexi Expander LED dimming

#### **30.12.2024** Firmware #7.045

* Firmware: Effect Loop Insert provision for HX3.7 board
* Organ Models: Less manual output levels to prevent Rotary Sim crossover distortions
* Speaker Models: Less input levels to prevent Rotary Sim distortions on some speaker models

#### **23.09.2024** Firmware #6.044

* Firmware: Drawbars moved slowly did not always return to zero when pushed fully in

#### **23.07.2024** Firmware #6.043, Fatar Scan Driver #61.46

* Firmware: **Bugfix**, Rotary params not saved when changed by MenuPanel
* Firmware/Editor: Misleading name "Local Enable" of parameter #1373 changed to "MIDI Send Enables" resp. "MIDI Send" in MenuPanel
* Scan Driver (Fatar): **Bugfix**, MIDI Send Enables parameter did not work

#### **31.06.2024** Firmware #6.042, FPGA #25062024, Scan Driver #6x.45

* Firmware, Editor: Support for new *Organ Models* parameter #1364, controls noisy "old/dry" (#1364=OFF) or quieter "new/lubed" (ON) mechanical key contacts
* Firmware, Editor: Support for new *Organ Models* parameter #1365, controls generator "loudness robbing" behaviour
* FPGA: Support for new/lubed contacts with elaborate contact resistance levels
* FPGA: More "compression" effect due to decreasing busbar and matching transformer load impedance when multiple notes played
* FPGA: New, more authentic approach for tone generator "loudness robbing" (drop 
  of note volume when TG wheel is accessed by multiple notes played) and "level 
  pumping/compression" (loss of drawbar volume when multiple notes played)
* Scan driver: Will produce a more authentic key-on- and key-off-click with different contact resistance levels applied

**Note:** Hammond organs with well-maintained (lubed) key contacts as well as newer 
Hammond keybed variants yield a somewhat **lower key click volume**. If a too 
loud key click is observed, update to newest firmware, FPGA and scan driver. 

*Organ Models* parameter #1365 switches compression and loudness robbing effect 
on or off. It should be ON for all tonewheel organ models.

File *Organ Models* should be updated as well. If you wish to keep your existing 
(modified or custom) organ models, set parameters #1364 and #1365 to ON or OFF in HX3 
Editor's *Organ Models* tab. Adjust *Contact Spring Flex* #1360 and *Contact 
Spring Damping* #1361 to personal taste. Click **Store as Organ Model** when done. 

New HX3.6 scan drivers **will no longer work** on HX3.5, so they have been 
renamed to **numbering scheme #6x.xx**. Please use new scan driver(s) #6x.45 
supplied in ZIP. Be sure to select the appropriate scan driver (Fatar, MIDI 
etc.) in *HX3 BootLoad* utility or *HX3 Updater*.

#### **10.04.2024** Firmware #6.040, Scan Driver #5x.44

* Firmware: Somewhat improved frequency response for B3 swell type 
* Firmware: Added Bit 6 "Separate Main/Pedal if RotaryBypass ON" in *System Inits* #1502, "Various 
Configurations 2" for separate plain organ/pedal outputs on mainboard jacks
* Firmware: Upper/Lower/Pedal Enables #1397..#1399 now part of presets (tab setting)
* Alternative scan driver with lower click noise volume ("lubed" contacts) available in separate ZIP file *scan_44.ZIP*

**Note:** It was not possible to get **separate** plain organ and pedal audio on 
main audio output jacks; when the RotaryBypass tab is ON, both organ and pedal audio are 
downmixed to mono on both Main L and R. This might be undesirable for customers 
**without** optional Extension Board when using an external rotary speaker.

When activated (checked), the new "Separate Main/Pedal if RotaryBypass ON" bit (in 
*System Inits*, parameter #1502) routes the plain organ and pedal audio separately to the 
mainboard L/R output channels when rotary/speaker simulation is bypassed. This bit should be 
OFF (unchecked) when an Extension Board is used as here both signals are present anyway.

### **09.04.2024** Firmware #6.039

* Firmware: Different dry/wet mixture approach for reverb. Params #1400..1402 now control dry/wet mixture, while analog control "Overall Reverb" #1086 controls mainly reverb time

**Note:** Some customers noted a "thin" reverb along with lower "Overall Reverb" #1086 
values. In the past, parameter #1086 also controlled wet/dry mixture, which was undesirable. I 
changed behaviour to reverb time control on "Overall Reverb" #1086 parameter, 
while reverb "wet" levels are solely set by params #1400..1402. Max. reverb time 
(i.e. "Overall Reverb" #1086 potentiometer range) for each of the 3 reverb program (2 
buttons) is still to be set by ''DSP Setup'' params #2005..#2007.

### **22.01.2024** FPGA #22012024

* FPGA/SoundEngine: Made some changes in rotary horn simulation to defeat artefacts on higher notes

#### **09.01.2024** Firmware #6.038

* Firmware/Editor: Added *System Inits* parameter #1502 *Various Configurations 2* bit 5 for swapping SLOW/FAST switch inputs (allows connection of Hammond halfmoon switches)

#### **22.12.2023** Firmware #6.037, FPGA #16122023 or #17122023

* Firmware: Split On/Off, Split Point and Split Mode added as saved preset parameter (saving *Tabs* enabled)
* FPGA/SoundEngine: Two versions #16122023 and #17122023 added to try out, with different bass reflex "holes" for rotor speaker 

**Note:** I'm not quite shure which FPGA/SoundEngine sounds best in respect off 
bass response. *fpgamain.bin* is version #10122023 with old bass response. I 
added two versions simulating different bass reflex "holes" to try out: #16122023 
(*fpgamain_16.bin*, 120 Hz reflex hole) and #17122023 (*fpgamain_17.bin*, 60 Hz 
reflex hole), both in *updates* directory. Please tell me your opinion.

#### **06.12.2023** Firmware #6.035, FPGA #10122023, Bootloader #1.07

* Firmware: Bugfix, digital inputs configured as switches were not read properly on startup
* Firmware: Removed "blinking LEDs on invalidated preset" feature
* FPGA: Removed diffusor from rotary horn main beam, less diffsor modulation to prevent "swirling" and grinding artefacts
* Bootloader: Support for slower SD Cards, Bootloader shuts down FPGA while loading files from SD to prevent corrupted images

**Note:** For Bootloader update to #1.07, board must be sent to KeyboardPartner for factory update (in case your SD Cards do not work properly).

#### **03.11.2023** Manager #6.11, Firmware #6.034

* Firmware: Bugfix, saving voice presets with CANCEL key did not work properly
* Manager/Editor: Added *System Inits* #1502 Various Configurations 2, Bit 4: Delayed Save with CANCEL key
* Manager/Editor: Parameter group will be refreshed to update descriptions after pop-up menu "Set subsequent Values..." is executed 

**Note:** When preset key inputs are configured as switches, HX3 will change preset 
or voice directly when "inverted" preset key is pressed, not on preset key 
release. This may also be appropriate with non-latching keys. A voice or preset 
is immediately saved by pressing the CANCEL key and then the desired save destination key. 

If bit 4 of param #1502 Various Configurations 2 is set, you must hold CANCEL key
for about 2 seconds and then the desired save destination key. This would 
prevent an unintended save of a voice or preset.

#### **03.11.2023** Manager #6.10, Firmware #6.033

* Firmware: Bugfix, MIDI CC Special Function #1674 did not handle Percussion and 1' disable properly
* Firmware: Added *Program Change Disable* submenu ("No ProgChgRcv") to MIDI menu - if ON, HX3 will not respond to MIDI program changes
* Firmware: Master Volume, Reverb Level and Tube Amp Gain saved to Preset when enabled in *System Inits*
* Firmware: Tube Amp Gain will be restored fom Preset when bit 5 of *Common Preset Save/Restore Mask* bits (System Inits #1498) is set
* Firmware: Corrected display of Save Destination in menu depending on *Common Preset Save/Restore Mask* bits (System Inits #1498)
* Firmware: Limited MIDI swell sending to 8ms cycle; heavy use of swell pedal did clog MIDI transmissions
* Manager: Added *Program Change Disable* Parameter *MIDI Setup* #1376

For changelog of older versions, see **HX3.6 Manager Current Firmware** directory.2, FPGA #25062024, Scan Driver #6x.45

* Firmware, Editor: Support for new *Organ Models* parameter #1364, controls noisy "old/dry" (#1364=OFF) or quieter "new/lubed" (ON) mechanical key contacts
* Firmware, Editor: Support for new *Organ Models* parameter #1365, controls generator "loudness robbing" behaviour
* FPGA: Support for new/lubed contacts with elaborate contact resistance levels
* FPGA: More "compression" effect due to decreasing busbar and matching transformer load impedance when multiple notes played
* FPGA: New, more authentic approach for tone generator "loudness robbing" (drop 
  of note volume when TG wheel is accessed by multiple notes played) and "level 
  pumping/compression" (loss of drawbar volume when multiple notes played)
* Scan driver: Will produce a more authentic key-on- and key-off-click with different contact resistance levels applied

**Note:** Hammond organs with well-maintained (lubed) key contacts as well as newer 
Hammond keybed variants yield a somewhat **lower key click volume**. If a too 
loud key click is observed, update to newest firmware, FPGA and scan driver. 

*Organ Models* parameter #1365 switches compression and loudness robbing effect 
on or off. It should be ON for all tonewheel organ models.

File *Organ Models* should be updated as well. If you wish to keep your existing 
(modified or custom) organ models, set parameters #1364 and #1365 to ON or OFF in HX3 
Editor's *Organ Models* tab. Adjust *Contact Spring Flex* #1360 and *Contact 
Spring Damping* #1361 to personal taste. Click **Store as Organ Model** when done. 

New HX3.6 scan drivers **will no longer work** on HX3.5, so they have been 
renamed to **numbering scheme #6x.xx**. Please use new scan driver(s) #6x.45 
supplied in ZIP. Be sure to select the appropriate scan driver (Fatar, MIDI 
etc.) in *HX3 BootLoad* utility or *HX3 Updater*.

#### **10.04.2024** Firmware #6.040, Scan Driver #5x.44

* Firmware: Somewhat improved frequency response for B3 swell type 
* Firmware: Added Bit 6 "Separate Main/Pedal if RotaryBypass ON" in *System Inits* #1502, "Various 
Configurations 2" for separate plain organ/pedal outputs on mainboard jacks
* Firmware: Upper/Lower/Pedal Enables #1397..#1399 now part of presets (tab setting)
* Alternative scan driver with lower click noise volume ("lubed" contacts) available in separate ZIP file *scan_44.ZIP*

**Note:** It was not possible to get **separate** plain organ and pedal audio on 
main audio output jacks; when the RotaryBypass tab is ON, both organ and pedal audio are 
downmixed to mono on both Main L and R. This might be undesirable for customers 
**without** optional Extension Board when using an external rotary speaker.

When activated (checked), the new "Separate Main/Pedal if RotaryBypass ON" bit (in 
*System Inits*, parameter #1502) routes the plain organ and pedal audio separately to the 
mainboard L/R output channels when rotary/speaker simulation is bypassed. This bit should be 
OFF (unchecked) when an Extension Board is used as here both signals are present anyway.

### **09.04.2024** Firmware #6.039

* Firmware: Different dry/wet mixture approach for reverb. Params #1400..1402 now control dry/wet mixture, while analog control "Overall Reverb" #1086 controls mainly reverb time

**Note:** Some customers noted a "thin" reverb along with lower "Overall Reverb" #1086 
values. In the past, parameter #1086 also controlled wet/dry mixture, which was undesirable. I 
changed behaviour to reverb time control on "Overall Reverb" #1086 parameter, 
while reverb "wet" levels are solely set by params #1400..1402. Max. reverb time 
(i.e. "Overall Reverb" #1086 potentiometer range) for each of the 3 reverb program (2 
buttons) is still to be set by ''DSP Setup'' params #2005..#2007.

### **22.01.2024** FPGA #22012024

* FPGA/SoundEngine: Made some changes in rotary horn simulation to defeat artefacts on higher notes

#### **09.01.2024** Firmware #6.038

* Firmware/Editor: Added *System Inits* parameter #1502 *Various Configurations 2* bit 5 for swapping SLOW/FAST switch inputs (allows connection of Hammond halfmoon switches)

#### **22.12.2023** Firmware #6.037, FPGA #16122023 or #17122023

* Firmware: Split On/Off, Split Point and Split Mode added as saved preset parameter (saving *Tabs* enabled)
* FPGA/SoundEngine: Two versions #16122023 and #17122023 added to try out, with different bass reflex "holes" for rotor speaker 

**Note:** I'm not quite shure which FPGA/SoundEngine sounds best in respect off 
bass response. *fpgamain.bin* is version #10122023 with old bass response. I 
added two versions simulating different bass reflex "holes" to try out: #16122023 
(*fpgamain_16.bin*, 120 Hz reflex hole) and #17122023 (*fpgamain_17.bin*, 60 Hz 
reflex hole), both in *updates* directory. Please tell me your opinion.

#### **06.12.2023** Firmware #6.035, FPGA #10122023, Bootloader #1.07

* Firmware: Bugfix, digital inputs configured as switches were not read properly on startup
* Firmware: Removed "blinking LEDs on invalidated preset" feature
* FPGA: Removed diffusor from rotary horn main beam, less diffsor modulation to prevent "swirling" and grinding artefacts
* Bootloader: Support for slower SD Cards, Bootloader shuts down FPGA while loading files from SD to prevent corrupted images

**Note:** For Bootloader update to #1.07, board must be sent to KeyboardPartner for factory update (in case your SD Cards do not work properly).

#### **03.11.2023** Manager #6.11, Firmware #6.034

* Firmware: Bugfix, saving voice presets with CANCEL key did not work properly
* Manager/Editor: Added *System Inits* #1502 Various Configurations 2, Bit 4: Delayed Save with CANCEL key
* Manager/Editor: Parameter group will be refreshed to update descriptions after pop-up menu "Set subsequent Values..." is executed 

**Note:** When preset key inputs are configured as switches, HX3 will change preset 
or voice directly when "inverted" preset key is pressed, not on preset key 
release. This may also be appropriate with non-latching keys. A voice or preset 
is immediately saved by pressing the CANCEL key and then the desired save destination key. 

If bit 4 of param #1502 Various Configurations 2 is set, you must hold CANCEL key
for about 2 seconds and then the desired save destination key. This would 
prevent an unintended save of a voice or preset.

#### **03.11.2023** Manager #6.10, Firmware #6.033

* Firmware: Bugfix, MIDI CC Special Function #1674 did not handle Percussion and 1' disable properly
* Firmware: Added *Program Change Disable* submenu ("No ProgChgRcv") to MIDI menu - if ON, HX3 will not respond to MIDI program changes
* Firmware: Master Volume, Reverb Level and Tube Amp Gain saved to Preset when enabled in *System Inits*
* Firmware: Tube Amp Gain will be restored fom Preset when bit 5 of *Common Preset Save/Restore Mask* bits (System Inits #1498) is set
* Firmware: Corrected display of Save Destination in menu depending on *Common Preset Save/Restore Mask* bits (System Inits #1498)
* Firmware: Limited MIDI swell sending to 8ms cycle; heavy use of swell pedal did clog MIDI transmissions
* Manager: Added *Program Change Disable* Parameter *MIDI Setup* #1376

For changelog of older versions, see **HX3.6 Manager Current Firmware** directory. external FX insert in Tab group 5 (Expander Pro)
* DSP Firmware: **Bugfix**, reverb output no longer routed to plain organ out (feedback problem)
* DSP Firmware: Will identify as "HX3 Sound Engine" in Windows Device Manager (was "HX3.5" even on HX3.7 boards before)

**Note:** To update DSP firmware, set board to BL mode and use "Single DFU File" 
update button in HX3 Manager's **BootLoad** utility. Open "dsp_fw.dfu" resp. "dsp_fw_NoGM.dfu" 
file.

#### **19.03.2025** Firmware #7.047, FPGA #10022025

* Firmware/FPGA: Adjustable LED brightness for MIDI/Pro Expander, small bug in LED driver fixed
* Manager/CC Set Editor: Removed restrictions for CC Set DAT and CSV file names
* Manager: Open/Save dialogs streamlined
* FPGA: Support for external FX insert and Plexi Expander LED dimming

#### **30.12.2024** Firmware #7.045

* Firmware: Effect Loop Insert provision for HX3.7 board
* Organ Models: Less manual output levels to prevent Rotary Sim crossover distortions
* Speaker Models: Less input levels to prevent Rotary Sim distortions on some speaker models

#### **23.09.2024** Firmware #6.044

* Firmware: Drawbars moved slowly did not always return to zero when pushed fully in

#### **23.07.2024** Firmware #6.043, Fatar Scan Driver #61.46

* Firmware: **Bugfix**, Rotary params not saved when changed by MenuPanel
* Firmware/Editor: Misleading name "Local Enable" of parameter #1373 changed to "MIDI Send Enables" resp. "MIDI Send" in MenuPanel
* Scan Driver (Fatar): **Bugfix**, MIDI Send Enables parameter did not work

#### **31.06.2024** Firmware #6.042, FPGA #25062024, Scan Driver #6x.45

* Firmware, Editor: Support for new *Organ Models* parameter #1364, controls noisy "old/dry" (#1364=OFF) or quieter "new/lubed" (ON) mechanical key contacts
* Firmware, Editor: Support for new *Organ Models* parameter #1365, controls generator "loudness robbing" behaviour
* FPGA: Support for new/lubed contacts with elaborate contact resistance levels
* FPGA: More "compression" effect due to decreasing busbar and matching transformer load impedance when multiple notes played
* FPGA: New, more authentic approach for tone generator "loudness robbing" (drop 
  of note volume when TG wheel is accessed by multiple notes played) and "level 
  pumping/compression" (loss of drawbar volume when multiple notes played)
* Scan driver: Will produce a more authentic key-on- and key-off-click with different contact resistance levels applied

**Note:** Hammond organs with well-maintained (lubed) key contacts as well as newer 
Hammond keybed variants yield a somewhat **lower key click volume**. If a too 
loud key click is observed, update to newest firmware, FPGA and scan driver. 

*Organ Models* parameter #1365 switches compression and loudness robbing effect 
on or off. It should be ON for all tonewheel organ models.

File *Organ Models* should be updated as well. If you wish to keep your existing 
(modified or custom) organ models, set parameters #1364 and #1365 to ON or OFF in HX3 
Editor's *Organ Models* tab. Adjust *Contact Spring Flex* #1360 and *Contact 
Spring Damping* #1361 to personal taste. Click **Store as Organ Model** when done. 

New HX3.6 scan drivers **will no longer work** on HX3.5, so they have been 
renamed to **numbering scheme #6x.xx**. Please use new scan driver(s) #6x.45 
supplied in ZIP. Be sure to select the appropriate scan driver (Fatar, MIDI 
etc.) in *HX3 BootLoad* utility or *HX3 Updater*.

#### **10.04.2024** Firmware #6.040, Scan Driver #5x.44

* Firmware: Somewhat improved frequency response for B3 swell type 
* Firmware: Added Bit 6 "Separate Main/Pedal if RotaryBypass ON" in *System Inits* #1502, "Various 
Configurations 2" for separate plain organ/pedal outputs on mainboard jacks
* Firmware: Upper/Lower/Pedal Enables #1397..#1399 now part of presets (tab setting)
* Alternative scan driver with lower click noise volume ("lubed" contacts) available in separate ZIP file *scan_44.ZIP*

**Note:** It was not possible to get **separate** plain organ and pedal audio on 
main audio output jacks; when the RotaryBypass tab is ON, both organ and pedal audio are 
downmixed to mono on both Main L and R. This might be undesirable for customers 
**without** optional Extension Board when using an external rotary speaker.

When activated (checked), the new "Separate Main/Pedal if RotaryBypass ON" bit (in 
*System Inits*, parameter #1502) routes the plain organ and pedal audio separately to the 
mainboard L/R output channels when rotary/speaker simulation is bypassed. This bit should be 
OFF (unchecked) when an Extension Board is used as here both signals are present anyway.

### **09.04.2024** Firmware #6.039

* Firmware: Different dry/wet mixture approach for reverb. Params #1400..1402 now control dry/wet mixture, while analog control "Overall Reverb" #1086 controls mainly reverb time

**Note:** Some customers noted a "thin" reverb along with lower "Overall Reverb" #1086 
values. In the past, parameter #1086 also controlled wet/dry mixture, which was undesirable. I 
changed behaviour to reverb time control on "Overall Reverb" #1086 parameter, 
while reverb "wet" levels are solely set by params #1400..1402. Max. reverb time 
(i.e. "Overall Reverb" #1086 potentiometer range) for each of the 3 reverb program (2 
buttons) is still to be set by ''DSP Setup'' params #2005..#2007.

### **22.01.2024** FPGA #22012024

* FPGA/SoundEngine: Made some changes in rotary horn simulation to defeat artefacts on higher notes

#### **09.01.2024** Firmware #6.038

* Firmware/Editor: Added *System Inits* parameter #1502 *Various Configurations 2* bit 5 for swapping SLOW/FAST switch inputs (allows connection of Hammond halfmoon switches)

#### **22.12.2023** Firmware #6.037, FPGA #16122023 or #17122023

* Firmware: Split On/Off, Split Point and Split Mode added as saved preset parameter (saving *Tabs* enabled)
* FPGA/SoundEngine: Two versions #16122023 and #17122023 added to try out, with different bass reflex "holes" for rotor speaker 

**Note:** I'm not quite shure which FPGA/SoundEngine sounds best in respect off 
bass response. *fpgamain.bin* is version #10122023 with old bass response. I 
added two versions simulating different bass reflex "holes" to try out: #16122023 
(*fpgamain_16.bin*, 120 Hz reflex hole) and #17122023 (*fpgamain_17.bin*, 60 Hz 
reflex hole), both in *updates* directory. Please tell me your opinion.

#### **06.12.2023** Firmware #6.035, FPGA #10122023, Bootloader #1.07

* Firmware: Bugfix, digital inputs configured as switches were not read properly on startup
* Firmware: Removed "blinking LEDs on invalidated preset" feature
* FPGA: Removed diffusor from rotary horn main beam, less diffsor modulation to prevent "swirling" and grinding artefacts
* Bootloader: Support for slower SD Cards, Bootloader shuts down FPGA while loading files from SD to prevent corrupted images

**Note:** For Bootloader update to #1.07, board must be sent to KeyboardPartner for factory update (in case your SD Cards do not work properly).

#### **03.11.2023** Manager #6.11, Firmware #6.034

* Firmware: Bugfix, saving voice presets with CANCEL key did not work properly
* Manager/Editor: Added *System Inits* #1502 Various Configurations 2, Bit 4: Delayed Save with CANCEL key
* Manager/Editor: Parameter group will be refreshed to update descriptions after pop-up menu "Set subsequent Values..." is executed 

**Note:** When preset key inputs are configured as switches, HX3 will change preset 
or voice directly when "inverted" preset key is pressed, not on preset key 
release. This may also be appropriate with non-latching keys. A voice or preset 
is immediately saved by pressing the CANCEL key and then the desired save destination key. 

If bit 4 of param #1502 Various Configurations 2 is set, you must hold CANCEL key
for about 2 seconds and then the desired save destination key. This would 
prevent an unintended save of a voice or preset.

#### **03.11.2023** Manager #6.10, Firmware #6.033

* Firmware: Bugfix, MIDI CC Special Function #1674 did not handle Percussion and 1' disable properly
* Firmware: Added *Program Change Disable* submenu ("No ProgChgRcv") to MIDI menu - if ON, HX3 will not respond to MIDI program changes
* Firmware: Master Volume, Reverb Level and Tube Amp Gain saved to Preset when enabled in *System Inits*
* Firmware: Tube Amp Gain will be restored fom Preset when bit 5 of *Common Preset Save/Restore Mask* bits (System Inits #1498) is set
* Firmware: Corrected display of Save Destination in menu depending on *Common Preset Save/Restore Mask* bits (System Inits #1498)
* Firmware: Limited MIDI swell sending to 8ms cycle; heavy use of swell pedal did clog MIDI transmissions
* Manager: Added *Program Change Disable* Parameter *MIDI Setup* #1376

For changelog of older versions, see **HX3.6 Manager Current Firmware** directory.