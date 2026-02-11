// Text alignment
// Usage: internally used by VTFT stack
const taNone:    TTextAlign; external;
const taLeft:    TTextAlign; external;
const taCenter:  TTextAlign; external;
const taRight:   TTextAlign; external;
const taCenterX: TTextAlign; external;
const taCenterY: TTextAlign; external;
const taRightX:  TTextAlign; external;
// ~Text alignment

// Object type constants
// Usage: VTFT stack internally
const VTFT_OT_BUTTONROUND:  byte; external;
const VTFT_OT_LABEL:        byte; external;
const VTFT_OT_CLABEL:       byte; external;
const VTFT_OT_CCIRCLE:      byte; external;
const VTFT_OT_CIRCLEBUTTON: byte; external;
const VTFT_OT_BOX:          byte; external;
const VTFT_OT_CBOX:         byte; external;
const VTFT_OT_BOXROUND:     byte; external;
const VTFT_OT_CBOXROUND:    byte; external;
const VTFT_OT_LINE:         byte; external;
const VTFT_OT_CLINE:        byte; external;
const VTFT_OT_CHECKBOX:     byte; external;
const VTFT_OT_EVEDIAL:      byte; external;
const VTFT_OT_EVEKEYS:      byte; external;
const VTFT_OT_EVESCROLLBAR: byte; external;
const VTFT_OT_EVESLIDER:    byte; external;
const VTFT_OT_EVETEXT:      byte; external;
const VTFT_OT_EVENUMBER:    byte; external;
// ~Object type constants

// Event type constants
// Usage: OnEvent
const VTFT_EVT_UP:    byte; external;
const VTFT_EVT_DOWN:  byte; external;
const VTFT_EVT_CLICK: byte; external;
const VTFT_EVT_PRESS: byte; external;
// ~Event type constants

// Sound action constants
// Usage: sound event action property and ProcessEvent
const VTFT_SNDACT_NONE: byte; external;
const VTFT_SNDACT_PLAY: byte; external;
const VTFT_SNDACT_STOP: byte; external;
// ~Sound action constants

// Resource loading constants.
// Usage: DrawScreenO and LoadCurrentScreenResToGRAM
const VTFT_LOAD_RES_NONE:    byte; external;
const VTFT_LOAD_RES_STATIC:  byte; external;
const VTFT_LOAD_RES_DYNAMIC: byte; external;
const VTFT_LOAD_RES_ALL:     byte; external;
// ~Resource loading constants

// Display effect constants
// Usage: DrawScreenO
const VTFT_DISPLAY_EFF_NONE:        byte; external;
const VTFT_DISPLAY_EFF_LIGHTS_FADE: byte; external;
const VTFT_DISPLAY_EFF_LIGHTS_OFF:  byte; external;
// ~Display effect constants

// Stack flags
// Usage: internally used by VTFT stack
const VTFT_INT_REPAINT_ON_DOWN:     byte; external;
const VTFT_INT_REPAINT_ON_UP:       byte; external;
const VTFT_INT_BRING_TO_FRONT:      byte; external;
const VTFT_INT_INTRINSIC_CLICK_EFF: byte; external;
// ~Stack flags

// Default configuration parameters
const VTFT_FT800_CONFIG_PWM: TFT800PWM; external;
const VTFT_FT800_CONFIG_GPIO: TFT800GPIO; external;
const VTFT_FT800_CONFIG_SOUND: TFT800Sound; external;
const VTFT_FT800_CONFIG_AUDIO: TFT800Audio; external;
const VTFT_FT800_CONFIG_DISPLAY: TFT800Display; external;
const VTFT_FT800_CONFIG_INTERRUPT: TFT800Interrupt; external;
const VTFT_FT800_CONFIG_TOUCH: TFT800Touch; external;
const VTFT_FT800_CONFIG_TOUCHTRANSFORM: TFT800TouchTransform; external;
// ~Default configuration parameters


var CurrentScreen: ^TScreen; external;
var TouchS: TTouchStat; external;

// Routine declarations
procedure DrawScreenO(aScreen: ^TScreen; aOptions: byte); external;
procedure DrawScreen(aScreen: ^TScreen); external;
procedure DrawButtonRound(AButtonRound: TButton_RoundPtr); external;
procedure DrawLabel(ALabel: TLabelPtr); external;
procedure DrawCLabel(ACLabel: TCLabelPtr); external;
procedure DrawCCircle(ACCircle: TCCirclePtr); external;
procedure DrawCircleButton(ACircleButton: TCircleButtonPtr); external;
procedure DrawBox(ABox: TBoxPtr); external;
procedure DrawCBox(ACBox: TCBoxPtr); external;
procedure DrawBoxRound(ABoxRound: TBox_RoundPtr); external;
procedure DrawCBoxRound(ACBoxRound: TCBox_RoundPtr); external;
procedure DrawLine(ALine: TLinePtr); external;
procedure DrawCLine(ACLine: TCLinePtr); external;
procedure DrawCheckBox(ACheckBox: TCheckBoxPtr); external;
procedure DrawEveDial(AEveDial: TEveDialPtr); external;
procedure DrawEveKeys(AEveKeys: TEveKeysPtr); external;
procedure DrawEveScrollBar(AEveScrollBar: TEveScrollbarPtr); external;
procedure DrawEveSlider(AEveSlider: TEveSliderPtr); external;
procedure DrawEveText(AEveText: TEveTextPtr); external;
procedure DrawEveNumber(AEveNumber: TEveNumberPtr); external;
procedure ProcessVTFTStack(); external;
procedure InitVTFTStack(); external;
// ~Routine declarations


