// #############################################################################
// ####                        ACTION-TABELLE                               ####
// #############################################################################

// Diese Tabelle enthält alle Indexe auf Routinen-Adressen in ac_proclist,
// die bei Änderung eines edit-Wertes aufgerufen werden müssen.

// Bei Änderungen REBUILD ALL SOURCES!

ac_proc_idx: Array[0..c_edit_array_len] of byte = (
    32,  // Upper Drawbar 16
    32,  // Upper Drawbar 5 1/3
    32,  // Upper Drawbar 8
    32,  // Upper Drawbar 4
    32,  // Upper Drawbar 2 2/3
    32,  // Upper Drawbar 2
    32,  // Upper Drawbar 1 3/5
    32,  // Upper Drawbar 1 1/3
    32,  // Upper Drawbar 1
    32,  // Upper Mixture Drawbar 10
    32,  // Upper Mixture Drawbar 11
    32,  // Upper Mixture Drawbar 12
    39,  //
    39,  //
    39,  //
    39,  //
    33,  // Lower Drawbar 16
    33,  // Lower Drawbar 5 1/3
    33,  // Lower Drawbar 8
    33,  // Lower Drawbar 4
    33,  // Lower Drawbar 2 2/3
    33,  // Lower Drawbar 2
    33,  // Lower Drawbar 1 3/5
    33,  // Lower Drawbar 1 1/3
    33,  // Lower Drawbar 1
    33,  // Lower Mixture Drawbar 10
    33,  // Lower Mixture Drawbar 11
    33,  // Lower Mixture Drawbar 12
    39,  //
    39,  //
    39,  //
    39,  //
    35,  // Pedal Drawbar 16
    35,  // Pedal Drawbar 5 1/3
    35,  // Pedal Drawbar 8
    35,  // Pedal Drawbar 4
    35,  // Pedal Drawbar 2 2/3
    35,  // Pedal Drawbar 2
    35,  // Pedal Drawbar 1 3/5
    35,  // Pedal Drawbar 1 1/3
    35,  // Pedal Drawbar 1
    35,  // Pedal Mixture Drawbar 10
    35,  // Pedal Mixture Drawbar 11
    35,  // Pedal Mixture Drawbar 12
    39,  //
    39,  //
    39,  //
    39,  //
    32,  // Upper Attack
    32,  // Upper Decay
    32,  // Upper Sustain
    32,  // Upper Release
    32,  // Upper ADSR Harmonic Decay
    39,  //
    39,  //
    39,  //
    33,  // Lower Attack
    33,  // Lower Decay
    33,  // Lower Sustain
    33,  // Lower Release
    33,  // Lower ADSR Harmonic Decay
    39,  //
    39,  //
    39,  //
    35,  // Pedal Attack
    35,  // Pedal Decay
    35,  // Pedal Sustain
    35,  // Pedal Release
    35,  // Pedal ADSR Harmonic Decay
    39,  //
    39,  //
    39,  //
    34,  // Pedal Drawbar 16 AutoMix
    34,  // Pedal Drawbar 16H AutoMix
    34,  // Pedal Drawbar 8 AutoMix
    34,  // Pedal Drawbar 8H AutoMix
    39,  // Pitchwheel MIDI Send
    15,  // Pitchwheel Rotary Control
    15,  // Modwheel MIDI Send
    15,  // Modwheel Rotary Control
    30,  // General Master Volume
    30,  // Rotary Simulation Tube Amp Gain
    30,  // Upper Manual Level
    30,  // Lower Manual Level
    30,  // Pedal Level
    30,  // Upper Dry/2ndVoice Level
    7,  // Overall Reverb Level
    30,  // Tone Pot Equ
    30,  // Trim Cap Swell
    30,  // Minimal Swell Level
    30,  // AO 28 Triode Distortion
    30,  // Böhm Module Reverb Volume
    30,  // Böhm Module Efx Volume
    30,  // Böhm Module Swell Volume
    30,  // Böhm Module Front Volume
    30,  // Böhm Module Rear Volume
    32,  // Upper Envelope Drawbar 16
    32,  // Upper Envelope Drawbar 5 1/3
    32,  // Upper Envelope Drawbar 8
    32,  // Upper Envelope Drawbar 4
    32,  // Upper Envelope Drawbar 2 2/3
    32,  // Upper Envelope Drawbar 2
    32,  // Upper Envelope Drawbar 1 3/5
    32,  // Upper Envelope Drawbar 1 1/3
    32,  // Upper Envelope Drawbar 1
    32,  // Upper Envelope Mixture Drawbar 10
    32,  // Upper Envelope Mixture Drawbar 11
    32,  // Upper Envelope Mixture Drawbar 12
    39,  //
    39,  //
    39,  //
    39,  //
    29,  // Equ Bass Control
    29,  // Equ Bass Frequency if FullParametric
    29,  // Equ Bass Peak/Q if FullParametric
    29,  // Equ Mid Control
    29,  // Equ Mid Frequency
    29,  // Equ Mid Peak/Q
    29,  // Equ Treble Control
    29,  // Equ Treble Frequency if FullParametric
    29,  // Equ Treble Peak/Q if FullParametric
    29,  // Equ FullParametric Enable
    30,  // Böhm Module Ext Rotary Volume Left
    30,  // Böhm Module Ext Rotary Volume Right
    28,  // Equ Bass Gain Pot Mid Position
    28,  // Equ Mid Gain Pot Mid Position
    28,  // Equ Treble Gain Pot Mid Position
    28,  // Perc/Dry Volume Mid Position
    31,  // Percussion ON
    31,  // Percussion SOFT
    31,  // Percussion FAST
    31,  // Percussion THIRD
    11,  // Vibrato Upper ON
    11,  // Vibrato Lower ON
    15,  // Leslie RUN
    15,  // Leslie FAST
    11,  // Tube Amp Bypass
    11,  // Rotary Speaker Bypass
    11,  // Phasing Rotor upper ON
    11,  // Phasing Rotor lower ON
    5,  // Reverb 1
    5,  // Reverb 2
    11,  // Add Pedal
    27,  // Keyboard Split ON
    12,  // Phasing Rotor
    12,  // Phasing Rotor Ensemble
    12,  // Phasing Rotor Celeste
    12,  // Phasing Rotor Fading
    12,  // Phasing Rotor Weak
    12,  // Phasing Rotor Deep
    12,  // Phasing Rotor Fast
    12,  // Phasing Rotor Delay
    39,  // TAB #24, H100 Mode
    39,  // TAB #25, Envelope Generator (EG) Mode
    39,  // TAB #26, EG Percussion Drawbar Mode
    39,  // TAB #27, EG TimeBend Drawbar Mode
    0,  // TAB #28, H100 2ndVoice (Perc Decay Bypass)
    0,  // TAB #29, H100 Harp Sustain
    0,  // TAB #30, EG Enables to Dry Channel
    11,  // TAB #31, Equalizer Bypass
    0,  // Upper Drawbar 16 to ADSR
    0,  // Upper Drawbar 5 1/3 to ADSR
    0,  // Upper Drawbar 8 to ADSR
    0,  // Upper Drawbar 4 to ADSR
    0,  // Upper Drawbar 2 2/3 to ADSR
    0,  // Upper Drawbar 2 to ADSR
    0,  // Upper Drawbar1 3/5 to ADSR
    0,  // Upper Drawbar 1 1/3 to ADSR
    0,  // Upper Drawbar 1 to ADSR
    0,  // Upper Mixture Drawbar 10 to ADSR
    0,  // Upper Mixture Drawbar 11 to ADSR
    0,  // Upper Mixture Drawbar 12 to ADSR
    39,  //
    39,  //
    27,  // Octave Downshift Upper
    27,  // Octave Downshift Lower
    33,  // Lower Drawbar 16 to ADSR
    33,  // Lower Drawbar 5 1/3 to ADSR
    33,  // Lower Drawbar 8 to ADSR
    33,  // Lower Drawbar 4 to ADSR
    33,  // Lower Drawbar 2 2/3 to ADSR
    33,  // Lower Drawbar 2 to ADSR
    33,  // Lower Drawbar1 3/5 to ADSR
    33,  // Lower Drawbar 1 1/3 to ADSR
    33,  // Lower Drawbar 1 to ADSR
    33,  // Lower Mixture Drawbar 10 to ADSR
    33,  // Lower Mixture Drawbar 11 to ADSR
    33,  // Lower Mixture Drawbar 12 to ADSR
    39,  //
    10,  // MIDI Upper Enable
    10,  // MIDI Lower Enable
    10,  // MIDI Pedal Enable
    39,  // Preset Name String [0] (Length Byte)
    39,  // Preset Name String [1]
    39,  // Preset Name String [2]
    39,  // Preset Name String [3]
    39,  // Preset Name String [4]
    39,  // Preset Name String [5]
    39,  // Preset Name String [6]
    39,  // Preset Name String [7]
    39,  // Preset Name String [8]
    39,  // Preset Name String [9]
    39,  // Preset Name String [10]
    39,  // Preset Name String [11]
    39,  // Preset Name String [12]
    39,  // Preset Name String [13]
    39,  // Preset Name String [14]
    39,  // Preset Name String [15]
    39,  // Hammond DB Upper Decode
    39,  // Hammond DB Lower Decode
    39,  // Hammond DB Pedal Decode
    39,  // Hammond VibKnob Decode
    39,  // 4 Btn V1
    39,  // 4 Btn V2
    39,  // 4 Btn V3
    39,  // 4 Btn V/C
    39,  // Transpose +1 UP
    39,  // Transpose -1 DOWN
    39,  // nicht abgespeicherte Buttons
    39,  // nicht abgespeicherte Buttons
    39,  // Single DB set to Lower
    39,  // Single DB set to Pedal
    39,  // nicht abgespeicherte Buttons
    39,  // nicht abgespeicherte Buttons
    24,  // Upper GM Layer 1 Voice
    19,  // Upper GM Layer 1 Level
    19,  // Upper GM Layer 1 Harmonic
    25,  // Upper GM Layer 2 Voice
    19,  // Upper GM Layer 2 Level
    19,  // Upper GM Layer 2 Harmonic
    19,  // Upper GM Layer 2 Detune
    39,  //
    20,  // Lower GM Layer 1 Voice
    17,  // Lower GM Layer 1 Level
    17,  // Lower GM Layer 1 Harmonic
    21,  // Lower GM Layer 2 Voice
    17,  // Lower GM Layer 2 Level
    17,  // Lower GM Layer 2 Harmonic
    17,  // Lower GM Layer 2 Detune
    39,  //
    22,  // Pedal GM Layer 1 Voice
    18,  // Pedal GM Layer 1 Level
    18,  // Pedal GM Layer 1 Harmonic
    23,  // Pedal GM Layer 2 Voice
    18,  // Pedal GM Layer 2 Level
    18,  // Pedal GM Layer 2 Harmonic
    18,  // Pedal GM Layer 2 Detune
    39,  // Save Event Defaults
    39,  // Save Event Organ
    39,  //
    39,  //
    39,  //
    39,  // Save Event Common
    39,  // Save Event Upper
    39,  // Save Event Lower
    39,  // Save Event Pedal
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    8,  // Vibrato Knob
    39,  // Organ Model (OSC)
    39,  //
    39,  //
    39,  // Overall Preset (Temp)
    39,  // Upper Voice
    39,  // Lower Voice
    39,  // Pedal Voice
    0,  // Level Busbar 16
    0,  // Level Busbar 5 1/3
    0,  // Level Busbar 8
    0,  // Level Busbar 4
    0,  // Level Busbar 2 2/3
    0,  // Level Busbar 2
    0,  // Level Busbar 1 3/5
    0,  // Level Busbar 1 1/3
    0,  // Level Busbar 1
    0,  // Level Busbar 10
    0,  // Level Busbar 11
    0,  // Level Busbar 12
    0,  // Level Busbar 13
    0,  // Level Busbar 14
    0,  // Level Busbar 15
    39,  //
    1,  // Note Offset Busbar 16
    1,  // Note Offset Busbar 5 1/3
    1,  // Note Offset Busbar 8
    1,  // Note Offset Busbar 4
    1,  // Note Offset Busbar 2 2/3
    1,  // Note Offset Busbar 2
    1,  // Note Offset Busbar 1 3/5
    1,  // Note Offset Busbar 1 1/3
    1,  // Note Offset Busbar 1
    1,  // Note Offset Busbar 10
    1,  // Note Offset Busbar 11
    1,  // Note Offset Busbar 12
    1,  // Note Offset Busbar 13
    1,  // Note Offset Busbar 14
    1,  // Note Offset Busbar 15
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    9,  // Pre-Emphasis (Treble Gain)
    9,  // LC Line Age/AM Amplitude Modulation
    9,  // LC Line Feedback
    9,  // LC Line Reflection
    9,  // LC Line Response Cutoff Frequency
    9,  // LC PhaseLk/Line Cutoff Shelving Level
    9,  // Scanner Gearing (Vib Frequ)
    9,  // Chorus Dry (Bypass) Level
    9,  // Chorus Wet (Scanner) Level
    9,  // Modulation V1/C1
    9,  // Modulation V2/C2
    9,  // Modulation V3/C3
    9,  // Modulation Chorus Enhance
    9,  // Scanner Segment Flutter
    9,  // Preemphasis Highpass Cutoff Frequ
    9,  // Modulation Slope, Preemph HP Phase/Peak
    39,  // PHR Speed Vari Slow (Temp)
    39,  // PHR Speed Vari Fast (Temp)
    13,  // PHR Speed Slow (Temp)
    13,  // PHR Feedback (Temp)
    13,  // PHR Level Ph1 (Temp)
    13,  // PHR Level Ph2 (Temp)
    13,  // PHR Level Ph3 (Temp)
    13,  // PHR Level Dry (Temp)
    13,  // PHR Feedback Invert (Temp)
    13,  // PHR Ramp Delay (Temp)
    13,  // PHR Mod Vari Ph1 (Temp)
    13,  // PHR Mod Vari Ph2 (Temp)
    13,  // PHR Mod Vari Ph3 (Temp)
    13,  // PHR Mod Slow Ph1 (Temp)
    13,  // PHR Mod Slow Ph2 (Temp)
    13,  // PHR Mod Slow Ph3 (Temp)
    0,  // Gating (Keying) Mode
    27,  // Keyboard Split Point if ON
    27,  // Keyboard Split Mode
    10,  // Keyboard Transpose
    10,  // Contact Early Action (Fatar Keybed only)
    10,  // No 1' Drawbar when Perc ON
    1,  // Drawbar 16' Foldback Mode
    1,  // Higher Foldback
    10,  // Contact Spring Flex
    10,  // Contact Spring Damping
    10,  // Percussion Enable On Live DB only
    10,  // Fatar Velocity Factor
    10,  //
    10,  //
    10,  //
    10,  //
    10,  // MIDI Channel
    10,  // MIDI Option
    26,  // MIDI CC Set
    10,  // MIDI Swell CC
    10,  // MIDI Volume CC
    16,  // MIDI Local Enable
    39,  // MIDI Preset CC
    39,  // MIDI Show CC
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    30,  // Preamp Swell Type
    3,  // TG Tuning Set
    1,  // TG Size
    1,  // TG Fixed Taper Value
    2,  // TG WaveSet
    10,  // TG Flutter
    10,  // TG Leakage
    10,  // TG Tuning
    1,  // TG Cap Set/Tapering
    1,  // TG LC Filter Fac
    1,  // TG Bottom 16' Octave Taper Val
    10,  // Generator/MIDI IN Transpose
    39,  // Generator Model Limit
    30,  // Organ Upper Manual Enable
    30,  // Organ Lower Manual Enable
    30,  // Organ Pedal Enable
    5,  // Reverb Level 1
    5,  // Reverb Level 2
    5,  // Reverb Level 3
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  // Current Mixture Setup Number
    39,  // Current Vibrato Setup Number
    39,  // Current Phasing Setup Number
    39,  // Current Percussion Menu Number
    39,  // Current Reverb Menu Number
    39,  //
    39,  //
    39,  //
    0,  // Mixt DB 10, Level from Busbar 9
    0,  // Mixt DB 10, Level from Busbar 10
    0,  // Mixt DB 10, Level from Busbar 11
    0,  // Mixt DB 10, Level from Busbar 12
    0,  // Mixt DB 10, Level from Busbar 13
    0,  // Mixt DB 10, Level from Busbar 14
    0,  //
    0,  //
    0,  // Mixt DB 11, Level from Busbar 9
    0,  // Mixt DB 11, Level from Busbar 10
    0,  // Mixt DB 11, Level from Busbar 11
    0,  // Mixt DB 11, Level from Busbar 12
    0,  // Mixt DB 11, Level from Busbar 13
    0,  // Mixt DB 11, Level from Busbar 14
    0,  //
    0,  //
    0,  // Mixt DB 12, Level from Busbar 9
    0,  // Mixt DB 12, Level from Busbar 10
    0,  // Mixt DB 12, Level from Busbar 11
    0,  // Mixt DB 12, Level from Busbar 12
    0,  // Mixt DB 12, Level from Busbar 13
    0,  // Mixt DB 12, Level from Busbar 14
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    39,  //
    14,  // Rotary Live Control, Horn Slow Time
    14,  // Rotary Live Control, Rotor Slow Time
    14,  // Rotary Live Control, Horn Fast Time
    14,  // Rotary Live Control, Rotor Fast Time
    14,  // Rotary Live Control, Horn Ramp Up Time
    14,  // Rotary Live Control, Rotor Ramp Up Time
    14,  // Rotary Live Control, Horn Ramp Down Time
    14,  // Rotary Live Control, Rotor Ramp Down Time
    14,  // Rotary Live Control, Speaker Throb Amount
    14,  // Rotary Live Control, Speaker Spread
    14,  // Rotary Live Control, Speaker Balance
    15,  // Sync PHR
    29,  // Rotary Amp: Tube A, old 6550 .. new EL34
    29,  // Rotary Amp: Tube B, old 6550 .. new EL34
    39,  //
    39,  //
    37,  // ENA_CONT_BITS (LSB), Drawbar 7..0
    37,  // ENA_CONT_BITS (MSB), Drawbar 11..8
    37,  // ENA_ENV_DB_BITS (LSB), Drawbar 7..0
    37,  // ENA_ENV_DB_BITS (MSB), Drawbar 11..8
    37,  // ENA_ENV_FULL_BITS (LSB), Drawbar 7..0
    37,  // ENA_ENV_FULL_BITS (MSB), Drawbar 11..8
    37,  // ENV_TO_DRY_BITS (LSB), Drawbar 7..0
    37,  // ENV_TO_DRY_BITS (MSB), Drawbar 11..8
    37,  // ENA_CONT_PERC_BITS (LSB), Drawbar 7..0
    37,  // ENA_CONT_PERC_BITS (MSB), Drawbar 11..8
    37,  // ENA_ENV_PERCMODE_BITS (LSB), Drawbar 7..0
    37,  // ENA_ENV_PERCMODE_BITS (MSB), Drawbar 11..8
    37,  // ENA_ENV_ADSRMODE_BITS (LSB), Drawbar 7..0
    37,  // ENA_ENV_ADSRMODE_BITS (MSB), Drawbar 11..8
    39,  //
    39,  //
    31,  // Perc Norm Level
    31,  // Perc Soft Level
    31,  // Perc Long Time
    31,  // Perc Short Time
    31,  // Perc Muted Level
    31,  //
    31,  // Perc Precharge Time
    39,  // Perc Ena on Live DB only
    39,  // (RFU)
    39,  // (RFU)
    16,  // GM2 Synth Volume
    16,  // Relative Organ Volume
    31,  // H100 Harp Sustain Time
    31,  // H100 2nd Voice Level
    39,  // (RFU)
    36,  // LED Dimmer
    39,  // (not used)
    39,  // Vibrato Knob Mode
    39,  // CommonPreset Save/Restore Mask
    39,  // (not used)
    39,  // (not used)
    39,  // Various Configurations 1
    39,  // Various Configurations 2
    39,  // ADC Configuration
    39,  // 1st DB Set Voice Number (enabled when 0..15)
    39,  // 2nd DB Set Voice Number (enabled when 1..15)
    39,  // Pedal Drawbar Configuration
    39,  // ADC Scaling
    39,  // (not used)
    39,  // HX3.5 Device Type
    39,  // Preset/EEPROM Structure Version
    39   // Magic Flag
  );