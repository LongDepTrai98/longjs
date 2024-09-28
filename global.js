//Global function 
const setTimeout = (cb, ms) => lj_timer(ms, 0, cb);
const setInterval = (cb, ms) => lj_timer(0, ms, cb); 
class Console {
    log(...args) {
        print(...args);
    }
}

var console = new Console(); 

const GL_ZERO = 0
const GL_FALSE = 0
const GL_LOGIC_OP = 0x0BF1
const GL_NONE = 0
const GL_TEXTURE_COMPONENTS = 0x1003
const GL_NO_ERROR = 0
const GL_POINTS = 0x0000
const GL_CURRENT_BIT = 0x00000001
const GL_TRUE = 1
const GL_ONE = 1
const GL_CLIENT_PIXEL_STORE_BIT = 0x00000001
const GL_LINES = 0x0001
const GL_LINE_LOOP = 0x0002
const GL_POINT_BIT = 0x00000002
const GL_CLIENT_VERTEX_ARRAY_BIT = 0x00000002
const GL_LINE_STRIP = 0x0003
const GL_LINE_BIT = 0x00000004
const GL_TRIANGLES = 0x0004
const GL_TRIANGLE_STRIP = 0x0005
const GL_TRIANGLE_FAN = 0x0006
const GL_QUADS = 0x0007
const GL_QUAD_STRIP = 0x0008
const GL_POLYGON_BIT = 0x00000008
const GL_POLYGON = 0x0009
const GL_POLYGON_STIPPLE_BIT = 0x00000010
const GL_PIXEL_MODE_BIT = 0x00000020
const GL_LIGHTING_BIT = 0x00000040
const GL_FOG_BIT = 0x00000080
const GL_DEPTH_BUFFER_BIT = 0x00000100
const GL_ACCUM = 0x0100
const GL_LOAD = 0x0101
const GL_RETURN = 0x0102
const GL_MULT = 0x0103
const GL_ADD = 0x0104
const GL_NEVER = 0x0200
const GL_ACCUM_BUFFER_BIT = 0x00000200
const GL_LESS = 0x0201
const GL_EQUAL = 0x0202
const GL_LEQUAL = 0x0203
const GL_GREATER = 0x0204
const GL_NOTEQUAL = 0x0205
const GL_GEQUAL = 0x0206
const GL_ALWAYS = 0x0207
const GL_SRC_COLOR = 0x0300
const GL_ONE_MINUS_SRC_COLOR = 0x0301
const GL_SRC_ALPHA = 0x0302
const GL_ONE_MINUS_SRC_ALPHA = 0x0303
const GL_DST_ALPHA = 0x0304
const GL_ONE_MINUS_DST_ALPHA = 0x0305
const GL_DST_COLOR = 0x0306
const GL_ONE_MINUS_DST_COLOR = 0x0307
const GL_SRC_ALPHA_SATURATE = 0x0308
const GL_STENCIL_BUFFER_BIT = 0x00000400
const GL_FRONT_LEFT = 0x0400
const GL_FRONT_RIGHT = 0x0401
const GL_BACK_LEFT = 0x0402
const GL_BACK_RIGHT = 0x0403
const GL_FRONT = 0x0404
const GL_BACK = 0x0405
const GL_LEFT = 0x0406
const GL_RIGHT = 0x0407
const GL_FRONT_AND_BACK = 0x0408
const GL_AUX0 = 0x0409
const GL_AUX1 = 0x040A
const GL_AUX2 = 0x040B
const GL_AUX3 = 0x040C
const GL_INVALID_ENUM = 0x0500
const GL_INVALID_VALUE = 0x0501
const GL_INVALID_OPERATION = 0x0502
const GL_STACK_OVERFLOW = 0x0503
const GL_STACK_UNDERFLOW = 0x0504
const GL_OUT_OF_MEMORY = 0x0505
const GL_2D = 0x0600
const GL_3D = 0x0601
const GL_3D_COLOR = 0x0602
const GL_3D_COLOR_TEXTURE = 0x0603
const GL_4D_COLOR_TEXTURE = 0x0604
const GL_PASS_THROUGH_TOKEN = 0x0700
const GL_POINT_TOKEN = 0x0701
const GL_LINE_TOKEN = 0x0702
const GL_POLYGON_TOKEN = 0x0703
const GL_BITMAP_TOKEN = 0x0704
const GL_DRAW_PIXEL_TOKEN = 0x0705
const GL_COPY_PIXEL_TOKEN = 0x0706
const GL_LINE_RESET_TOKEN = 0x0707
const GL_EXP = 0x0800
const GL_VIEWPORT_BIT = 0x00000800
const GL_EXP2 = 0x0801
const GL_CW = 0x0900
const GL_CCW = 0x0901
const GL_COEFF = 0x0A00
const GL_ORDER = 0x0A01
const GL_DOMAIN = 0x0A02
const GL_CURRENT_COLOR = 0x0B00
const GL_CURRENT_INDEX = 0x0B01
const GL_CURRENT_NORMAL = 0x0B02
const GL_CURRENT_TEXTURE_COORDS = 0x0B03
const GL_CURRENT_RASTER_COLOR = 0x0B04
const GL_CURRENT_RASTER_INDEX = 0x0B05
const GL_CURRENT_RASTER_TEXTURE_COORDS = 0x0B06
const GL_CURRENT_RASTER_POSITION = 0x0B07
const GL_CURRENT_RASTER_POSITION_VALID = 0x0B08
const GL_CURRENT_RASTER_DISTANCE = 0x0B09
const GL_POINT_SMOOTH = 0x0B10
const GL_POINT_SIZE = 0x0B11
const GL_POINT_SIZE_RANGE = 0x0B12
const GL_POINT_SIZE_GRANULARITY = 0x0B13
const GL_LINE_SMOOTH = 0x0B20
const GL_LINE_WIDTH = 0x0B21
const GL_LINE_WIDTH_RANGE = 0x0B22
const GL_LINE_WIDTH_GRANULARITY = 0x0B23
const GL_LINE_STIPPLE = 0x0B24
const GL_LINE_STIPPLE_PATTERN = 0x0B25
const GL_LINE_STIPPLE_REPEAT = 0x0B26
const GL_LIST_MODE = 0x0B30
const GL_MAX_LIST_NESTING = 0x0B31
const GL_LIST_BASE = 0x0B32
const GL_LIST_INDEX = 0x0B33
const GL_POLYGON_MODE = 0x0B40
const GL_POLYGON_SMOOTH = 0x0B41
const GL_POLYGON_STIPPLE = 0x0B42
const GL_EDGE_FLAG = 0x0B43
const GL_CULL_FACE = 0x0B44
const GL_CULL_FACE_MODE = 0x0B45
const GL_FRONT_FACE = 0x0B46
const GL_LIGHTING = 0x0B50
const GL_LIGHT_MODEL_LOCAL_VIEWER = 0x0B51
const GL_LIGHT_MODEL_TWO_SIDE = 0x0B52
const GL_LIGHT_MODEL_AMBIENT = 0x0B53
const GL_SHADE_MODEL = 0x0B54
const GL_COLOR_MATERIAL_FACE = 0x0B55
const GL_COLOR_MATERIAL_PARAMETER = 0x0B56
const GL_COLOR_MATERIAL = 0x0B57
const GL_FOG = 0x0B60
const GL_FOG_INDEX = 0x0B61
const GL_FOG_DENSITY = 0x0B62
const GL_FOG_START = 0x0B63
const GL_FOG_END = 0x0B64
const GL_FOG_MODE = 0x0B65
const GL_FOG_COLOR = 0x0B66
const GL_DEPTH_RANGE = 0x0B70
const GL_DEPTH_TEST = 0x0B71
const GL_DEPTH_WRITEMASK = 0x0B72
const GL_DEPTH_CLEAR_VALUE = 0x0B73
const GL_DEPTH_FUNC = 0x0B74
const GL_ACCUM_CLEAR_VALUE = 0x0B80
const GL_STENCIL_TEST = 0x0B90
const GL_STENCIL_CLEAR_VALUE = 0x0B91
const GL_STENCIL_FUNC = 0x0B92
const GL_STENCIL_VALUE_MASK = 0x0B93
const GL_STENCIL_FAIL = 0x0B94
const GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95
const GL_STENCIL_PASS_DEPTH_PASS = 0x0B96
const GL_STENCIL_REF = 0x0B97
const GL_STENCIL_WRITEMASK = 0x0B98
const GL_MATRIX_MODE = 0x0BA0
const GL_NORMALIZE = 0x0BA1
const GL_VIEWPORT = 0x0BA2
const GL_MODELVIEW_STACK_DEPTH = 0x0BA3
const GL_PROJECTION_STACK_DEPTH = 0x0BA4
const GL_TEXTURE_STACK_DEPTH = 0x0BA5
const GL_MODELVIEW_MATRIX = 0x0BA6
const GL_PROJECTION_MATRIX = 0x0BA7
const GL_TEXTURE_MATRIX = 0x0BA8
const GL_ATTRIB_STACK_DEPTH = 0x0BB0
const GL_CLIENT_ATTRIB_STACK_DEPTH = 0x0BB1
const GL_ALPHA_TEST = 0x0BC0
const GL_ALPHA_TEST_FUNC = 0x0BC1
const GL_ALPHA_TEST_REF = 0x0BC2
const GL_DITHER = 0x0BD0
const GL_BLEND_DST = 0x0BE0
const GL_BLEND_SRC = 0x0BE1
const GL_BLEND = 0x0BE2
const GL_LOGIC_OP_MODE = 0x0BF0
const GL_INDEX_LOGIC_OP = 0x0BF1
const GL_COLOR_LOGIC_OP = 0x0BF2
const GL_AUX_BUFFERS = 0x0C00
const GL_DRAW_BUFFER = 0x0C01
const GL_READ_BUFFER = 0x0C02
const GL_SCISSOR_BOX = 0x0C10
const GL_SCISSOR_TEST = 0x0C11
const GL_INDEX_CLEAR_VALUE = 0x0C20
const GL_INDEX_WRITEMASK = 0x0C21
const GL_COLOR_CLEAR_VALUE = 0x0C22
const GL_COLOR_WRITEMASK = 0x0C23
const GL_INDEX_MODE = 0x0C30
const GL_RGBA_MODE = 0x0C31
const GL_DOUBLEBUFFER = 0x0C32
const GL_STEREO = 0x0C33
const GL_RENDER_MODE = 0x0C40
const GL_PERSPECTIVE_CORRECTION_HINT = 0x0C50
const GL_POINT_SMOOTH_HINT = 0x0C51
const GL_LINE_SMOOTH_HINT = 0x0C52
const GL_POLYGON_SMOOTH_HINT = 0x0C53
const GL_FOG_HINT = 0x0C54
const GL_TEXTURE_GEN_S = 0x0C60
const GL_TEXTURE_GEN_T = 0x0C61
const GL_TEXTURE_GEN_R = 0x0C62
const GL_TEXTURE_GEN_Q = 0x0C63
const GL_PIXEL_MAP_I_TO_I = 0x0C70
const GL_PIXEL_MAP_S_TO_S = 0x0C71
const GL_PIXEL_MAP_I_TO_R = 0x0C72
const GL_PIXEL_MAP_I_TO_G = 0x0C73
const GL_PIXEL_MAP_I_TO_B = 0x0C74
const GL_PIXEL_MAP_I_TO_A = 0x0C75
const GL_PIXEL_MAP_R_TO_R = 0x0C76
const GL_PIXEL_MAP_G_TO_G = 0x0C77
const GL_PIXEL_MAP_B_TO_B = 0x0C78
const GL_PIXEL_MAP_A_TO_A = 0x0C79
const GL_PIXEL_MAP_I_TO_I_SIZE = 0x0CB0
const GL_PIXEL_MAP_S_TO_S_SIZE = 0x0CB1
const GL_PIXEL_MAP_I_TO_R_SIZE = 0x0CB2
const GL_PIXEL_MAP_I_TO_G_SIZE = 0x0CB3
const GL_PIXEL_MAP_I_TO_B_SIZE = 0x0CB4
const GL_PIXEL_MAP_I_TO_A_SIZE = 0x0CB5
const GL_PIXEL_MAP_R_TO_R_SIZE = 0x0CB6
const GL_PIXEL_MAP_G_TO_G_SIZE = 0x0CB7
const GL_PIXEL_MAP_B_TO_B_SIZE = 0x0CB8
const GL_PIXEL_MAP_A_TO_A_SIZE = 0x0CB9
const GL_UNPACK_SWAP_BYTES = 0x0CF0
const GL_UNPACK_LSB_FIRST = 0x0CF1
const GL_UNPACK_ROW_LENGTH = 0x0CF2
const GL_UNPACK_SKIP_ROWS = 0x0CF3
const GL_UNPACK_SKIP_PIXELS = 0x0CF4
const GL_UNPACK_ALIGNMENT = 0x0CF5
const GL_PACK_SWAP_BYTES = 0x0D00
const GL_PACK_LSB_FIRST = 0x0D01
const GL_PACK_ROW_LENGTH = 0x0D02
const GL_PACK_SKIP_ROWS = 0x0D03
const GL_PACK_SKIP_PIXELS = 0x0D04
const GL_PACK_ALIGNMENT = 0x0D05
const GL_MAP_COLOR = 0x0D10
const GL_MAP_STENCIL = 0x0D11
const GL_INDEX_SHIFT = 0x0D12
const GL_INDEX_OFFSET = 0x0D13
const GL_RED_SCALE = 0x0D14
const GL_RED_BIAS = 0x0D15
const GL_ZOOM_X = 0x0D16
const GL_ZOOM_Y = 0x0D17
const GL_GREEN_SCALE = 0x0D18
const GL_GREEN_BIAS = 0x0D19
const GL_BLUE_SCALE = 0x0D1A
const GL_BLUE_BIAS = 0x0D1B
const GL_ALPHA_SCALE = 0x0D1C
const GL_ALPHA_BIAS = 0x0D1D
const GL_DEPTH_SCALE = 0x0D1E
const GL_DEPTH_BIAS = 0x0D1F
const GL_MAX_EVAL_ORDER = 0x0D30
const GL_MAX_LIGHTS = 0x0D31
const GL_MAX_CLIP_PLANES = 0x0D32
const GL_MAX_TEXTURE_SIZE = 0x0D33
const GL_MAX_PIXEL_MAP_TABLE = 0x0D34
const GL_MAX_ATTRIB_STACK_DEPTH = 0x0D35
const GL_MAX_MODELVIEW_STACK_DEPTH = 0x0D36
const GL_MAX_NAME_STACK_DEPTH = 0x0D37
const GL_MAX_PROJECTION_STACK_DEPTH = 0x0D38
const GL_MAX_TEXTURE_STACK_DEPTH = 0x0D39
const GL_MAX_VIEWPORT_DIMS = 0x0D3A
const GL_MAX_CLIENT_ATTRIB_STACK_DEPTH = 0x0D3B
const GL_SUBPIXEL_BITS = 0x0D50
const GL_INDEX_BITS = 0x0D51
const GL_RED_BITS = 0x0D52
const GL_GREEN_BITS = 0x0D53
const GL_BLUE_BITS = 0x0D54
const GL_ALPHA_BITS = 0x0D55
const GL_DEPTH_BITS = 0x0D56
const GL_STENCIL_BITS = 0x0D57
const GL_ACCUM_RED_BITS = 0x0D58
const GL_ACCUM_GREEN_BITS = 0x0D59
const GL_ACCUM_BLUE_BITS = 0x0D5A
const GL_ACCUM_ALPHA_BITS = 0x0D5B
const GL_NAME_STACK_DEPTH = 0x0D70
const GL_AUTO_NORMAL = 0x0D80
const GL_MAP1_COLOR_4 = 0x0D90
const GL_MAP1_INDEX = 0x0D91
const GL_MAP1_NORMAL = 0x0D92
const GL_MAP1_TEXTURE_COORD_1 = 0x0D93
const GL_MAP1_TEXTURE_COORD_2 = 0x0D94
const GL_MAP1_TEXTURE_COORD_3 = 0x0D95
const GL_MAP1_TEXTURE_COORD_4 = 0x0D96
const GL_MAP1_VERTEX_3 = 0x0D97
const GL_MAP1_VERTEX_4 = 0x0D98
const GL_MAP2_COLOR_4 = 0x0DB0
const GL_MAP2_INDEX = 0x0DB1
const GL_MAP2_NORMAL = 0x0DB2
const GL_MAP2_TEXTURE_COORD_1 = 0x0DB3
const GL_MAP2_TEXTURE_COORD_2 = 0x0DB4
const GL_MAP2_TEXTURE_COORD_3 = 0x0DB5
const GL_MAP2_TEXTURE_COORD_4 = 0x0DB6
const GL_MAP2_VERTEX_3 = 0x0DB7
const GL_MAP2_VERTEX_4 = 0x0DB8
const GL_MAP1_GRID_DOMAIN = 0x0DD0
const GL_MAP1_GRID_SEGMENTS = 0x0DD1
const GL_MAP2_GRID_DOMAIN = 0x0DD2
const GL_MAP2_GRID_SEGMENTS = 0x0DD3
const GL_TEXTURE_1D = 0x0DE0
const GL_TEXTURE_2D = 0x0DE1
const GL_FEEDBACK_BUFFER_POINTER = 0x0DF0
const GL_FEEDBACK_BUFFER_SIZE = 0x0DF1
const GL_FEEDBACK_BUFFER_TYPE = 0x0DF2
const GL_SELECTION_BUFFER_POINTER = 0x0DF3
const GL_SELECTION_BUFFER_SIZE = 0x0DF4
const GL_TEXTURE_WIDTH = 0x1000
const GL_TRANSFORM_BIT = 0x00001000
const GL_TEXTURE_HEIGHT = 0x1001
const GL_TEXTURE_INTERNAL_FORMAT = 0x1003
const GL_TEXTURE_BORDER_COLOR = 0x1004
const GL_TEXTURE_BORDER = 0x1005
const GL_DONT_CARE = 0x1100
const GL_FASTEST = 0x1101
const GL_NICEST = 0x1102
const GL_AMBIENT = 0x1200
const GL_DIFFUSE = 0x1201
const GL_SPECULAR = 0x1202
const GL_POSITION = 0x1203
const GL_SPOT_DIRECTION = 0x1204
const GL_SPOT_EXPONENT = 0x1205
const GL_SPOT_CUTOFF = 0x1206
const GL_constANT_ATTENUATION = 0x1207
const GL_LINEAR_ATTENUATION = 0x1208
const GL_QUADRATIC_ATTENUATION = 0x1209
const GL_COMPILE = 0x1300
const GL_COMPILE_AND_EXECUTE = 0x1301
const GL_BYTE = 0x1400
const GL_UNSIGNED_BYTE = 0x1401
const GL_SHORT = 0x1402
const GL_UNSIGNED_SHORT = 0x1403
const GL_INT = 0x1404
const GL_UNSIGNED_INT = 0x1405
const GL_FLOAT = 0x1406
const GL_2_BYTES = 0x1407
const GL_3_BYTES = 0x1408
const GL_4_BYTES = 0x1409
const GL_DOUBLE = 0x140A
const GL_CLEAR = 0x1500
const GL_AND = 0x1501
const GL_AND_REVERSE = 0x1502
const GL_COPY = 0x1503
const GL_AND_INVERTED = 0x1504
const GL_NOOP = 0x1505
const GL_XOR = 0x1506
const GL_OR = 0x1507
const GL_NOR = 0x1508
const GL_EQUIV = 0x1509
const GL_INVERT = 0x150A
const GL_OR_REVERSE = 0x150B
const GL_COPY_INVERTED = 0x150C
const GL_OR_INVERTED = 0x150D
const GL_NAND = 0x150E
const GL_SET = 0x150F
const GL_EMISSION = 0x1600
const GL_SHININESS = 0x1601
const GL_AMBIENT_AND_DIFFUSE = 0x1602
const GL_COLOR_INDEXES = 0x1603
const GL_MODELVIEW = 0x1700
const GL_PROJECTION = 0x1701
const GL_TEXTURE = 0x1702
const GL_COLOR = 0x1800
const GL_DEPTH = 0x1801
const GL_STENCIL = 0x1802
const GL_COLOR_INDEX = 0x1900
const GL_STENCIL_INDEX = 0x1901
const GL_DEPTH_COMPONENT = 0x1902
const GL_RED = 0x1903
const GL_GREEN = 0x1904
const GL_BLUE = 0x1905
const GL_ALPHA = 0x1906
const GL_RGB = 0x1907
const GL_RGBA = 0x1908
const GL_LUMINANCE = 0x1909
const GL_LUMINANCE_ALPHA = 0x190A
const GL_BITMAP = 0x1A00
const GL_POINT = 0x1B00
const GL_LINE = 0x1B01
const GL_FILL = 0x1B02
const GL_RENDER = 0x1C00
const GL_FEEDBACK = 0x1C01
const GL_SELECT = 0x1C02
const GL_FLAT = 0x1D00
const GL_SMOOTH = 0x1D01
const GL_KEEP = 0x1E00
const GL_REPLACE = 0x1E01
const GL_INCR = 0x1E02
const GL_DECR = 0x1E03
const GL_VENDOR = 0x1F00
const GL_RENDERER = 0x1F01
const GL_VERSION = 0x1F02
const GL_EXTENSIONS = 0x1F03
const GL_S = 0x2000
const GL_ENABLE_BIT = 0x00002000
const GL_T = 0x2001
const GL_R = 0x2002
const GL_Q = 0x2003
const GL_MODULATE = 0x2100
const GL_DECAL = 0x2101
const GL_TEXTURE_ENV_MODE = 0x2200
const GL_TEXTURE_ENV_COLOR = 0x2201
const GL_TEXTURE_ENV = 0x2300
const GL_EYE_LINEAR = 0x2400
const GL_OBJECT_LINEAR = 0x2401
const GL_SPHERE_MAP = 0x2402
const GL_TEXTURE_GEN_MODE = 0x2500
const GL_OBJECT_PLANE = 0x2501
const GL_EYE_PLANE = 0x2502
const GL_NEAREST = 0x2600
const GL_LINEAR = 0x2601
const GL_NEAREST_MIPMAP_NEAREST = 0x2700
const GL_LINEAR_MIPMAP_NEAREST = 0x2701
const GL_NEAREST_MIPMAP_LINEAR = 0x2702
const GL_LINEAR_MIPMAP_LINEAR = 0x2703
const GL_TEXTURE_MAG_FILTER = 0x2800
const GL_TEXTURE_MIN_FILTER = 0x2801
const GL_TEXTURE_WRAP_S = 0x2802
const GL_TEXTURE_WRAP_T = 0x2803
const GL_CLAMP = 0x2900
const GL_REPEAT = 0x2901
const GL_POLYGON_OFFSET_UNITS = 0x2A00
const GL_POLYGON_OFFSET_POINT = 0x2A01
const GL_POLYGON_OFFSET_LINE = 0x2A02
const GL_R3_G3_B2 = 0x2A10
const GL_V2F = 0x2A20
const GL_V3F = 0x2A21
const GL_C4UB_V2F = 0x2A22
const GL_C4UB_V3F = 0x2A23
const GL_C3F_V3F = 0x2A24
const GL_N3F_V3F = 0x2A25
const GL_C4F_N3F_V3F = 0x2A26
const GL_T2F_V3F = 0x2A27
const GL_T4F_V4F = 0x2A28
const GL_T2F_C4UB_V3F = 0x2A29
const GL_T2F_C3F_V3F = 0x2A2A
const GL_T2F_N3F_V3F = 0x2A2B
const GL_T2F_C4F_N3F_V3F = 0x2A2C
const GL_T4F_C4F_N3F_V4F = 0x2A2D
const GL_CLIP_PLANE0 = 0x3000
const GL_CLIP_PLANE1 = 0x3001
const GL_CLIP_PLANE2 = 0x3002
const GL_CLIP_PLANE3 = 0x3003
const GL_CLIP_PLANE4 = 0x3004
const GL_CLIP_PLANE5 = 0x3005
const GL_LIGHT0 = 0x4000
const GL_COLOR_BUFFER_BIT = 0x00004000
const GL_LIGHT1 = 0x4001
const GL_LIGHT2 = 0x4002
const GL_LIGHT3 = 0x4003
const GL_LIGHT4 = 0x4004
const GL_LIGHT5 = 0x4005
const GL_LIGHT6 = 0x4006
const GL_LIGHT7 = 0x4007
const GL_HINT_BIT = 0x00008000
const GL_POLYGON_OFFSET_FILL = 0x8037
const GL_POLYGON_OFFSET_FACTOR = 0x8038
const GL_ALPHA4 = 0x803B
const GL_ALPHA8 = 0x803C
const GL_ALPHA12 = 0x803D
const GL_ALPHA16 = 0x803E
const GL_LUMINANCE4 = 0x803F
const GL_LUMINANCE8 = 0x8040
const GL_LUMINANCE12 = 0x8041
const GL_LUMINANCE16 = 0x8042
const GL_LUMINANCE4_ALPHA4 = 0x8043
const GL_LUMINANCE6_ALPHA2 = 0x8044
const GL_LUMINANCE8_ALPHA8 = 0x8045
const GL_LUMINANCE12_ALPHA4 = 0x8046
const GL_LUMINANCE12_ALPHA12 = 0x8047
const GL_LUMINANCE16_ALPHA16 = 0x8048
const GL_INTENSITY = 0x8049
const GL_INTENSITY4 = 0x804A
const GL_INTENSITY8 = 0x804B
const GL_INTENSITY12 = 0x804C
const GL_INTENSITY16 = 0x804D
const GL_RGB4 = 0x804F
const GL_RGB5 = 0x8050
const GL_RGB8 = 0x8051
const GL_RGB10 = 0x8052
const GL_RGB12 = 0x8053
const GL_RGB16 = 0x8054
const GL_RGBA2 = 0x8055
const GL_RGBA4 = 0x8056
const GL_RGB5_A1 = 0x8057
const GL_RGBA8 = 0x8058
const GL_RGB10_A2 = 0x8059
const GL_RGBA12 = 0x805A
const GL_RGBA16 = 0x805B
const GL_TEXTURE_RED_SIZE = 0x805C
const GL_TEXTURE_GREEN_SIZE = 0x805D
const GL_TEXTURE_BLUE_SIZE = 0x805E
const GL_TEXTURE_ALPHA_SIZE = 0x805F
const GL_TEXTURE_LUMINANCE_SIZE = 0x8060
const GL_TEXTURE_INTENSITY_SIZE = 0x8061
const GL_PROXY_TEXTURE_1D = 0x8063
const GL_PROXY_TEXTURE_2D = 0x8064
const GL_TEXTURE_PRIORITY = 0x8066
const GL_TEXTURE_RESIDENT = 0x8067
const GL_TEXTURE_BINDING_1D = 0x8068
const GL_TEXTURE_BINDING_2D = 0x8069
const GL_VERTEX_ARRAY = 0x8074
const GL_NORMAL_ARRAY = 0x8075
const GL_COLOR_ARRAY = 0x8076
const GL_INDEX_ARRAY = 0x8077
const GL_TEXTURE_COORD_ARRAY = 0x8078
const GL_EDGE_FLAG_ARRAY = 0x8079
const GL_VERTEX_ARRAY_SIZE = 0x807A
const GL_VERTEX_ARRAY_TYPE = 0x807B
const GL_VERTEX_ARRAY_STRIDE = 0x807C
const GL_NORMAL_ARRAY_TYPE = 0x807E
const GL_NORMAL_ARRAY_STRIDE = 0x807F
const GL_COLOR_ARRAY_SIZE = 0x8081
const GL_COLOR_ARRAY_TYPE = 0x8082
const GL_COLOR_ARRAY_STRIDE = 0x8083
const GL_INDEX_ARRAY_TYPE = 0x8085
const GL_INDEX_ARRAY_STRIDE = 0x8086
const GL_TEXTURE_COORD_ARRAY_SIZE = 0x8088
const GL_TEXTURE_COORD_ARRAY_TYPE = 0x8089
const GL_TEXTURE_COORD_ARRAY_STRIDE = 0x808A
const GL_EDGE_FLAG_ARRAY_STRIDE = 0x808C
const GL_VERTEX_ARRAY_POINTER = 0x808E
const GL_NORMAL_ARRAY_POINTER = 0x808F
const GL_COLOR_ARRAY_POINTER = 0x8090
const GL_INDEX_ARRAY_POINTER = 0x8091
const GL_TEXTURE_COORD_ARRAY_POINTER = 0x8092
const GL_EDGE_FLAG_ARRAY_POINTER = 0x8093
const GL_COLOR_INDEX1_EXT = 0x80E2
const GL_COLOR_INDEX2_EXT = 0x80E3
const GL_COLOR_INDEX4_EXT = 0x80E4
const GL_COLOR_INDEX8_EXT = 0x80E5
const GL_COLOR_INDEX12_EXT = 0x80E6
const GL_COLOR_INDEX16_EXT = 0x80E7
const GL_EVAL_BIT = 0x00010000
const GL_LIST_BIT = 0x00020000
const GL_TEXTURE_BIT = 0x00040000
const GL_SCISSOR_BIT = 0x00080000
const GL_ALL_ATTRIB_BITS = 0x000fffff
const GL_CLIENT_ALL_ATTRIB_BITS = 0xffffffff

const GL_BLEND_EQUATION_RGB = 0x8009
const GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622
const GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623
const GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624
const GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625
const GL_CURRENT_VERTEX_ATTRIB = 0x8626
const GL_VERTEX_PROGRAM_POINT_SIZE = 0x8642
const GL_VERTEX_PROGRAM_TWO_SIDE = 0x8643
const GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645
const GL_STENCIL_BACK_FUNC = 0x8800
const GL_STENCIL_BACK_FAIL = 0x8801
const GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802
const GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803
const GL_MAX_DRAW_BUFFERS = 0x8824
const GL_DRAW_BUFFER0 = 0x8825
const GL_DRAW_BUFFER1 = 0x8826
const GL_DRAW_BUFFER2 = 0x8827
const GL_DRAW_BUFFER3 = 0x8828
const GL_DRAW_BUFFER4 = 0x8829
const GL_DRAW_BUFFER5 = 0x882A
const GL_DRAW_BUFFER6 = 0x882B
const GL_DRAW_BUFFER7 = 0x882C
const GL_DRAW_BUFFER8 = 0x882D
const GL_DRAW_BUFFER9 = 0x882E
const GL_DRAW_BUFFER10 = 0x882F
const GL_DRAW_BUFFER11 = 0x8830
const GL_DRAW_BUFFER12 = 0x8831
const GL_DRAW_BUFFER13 = 0x8832
const GL_DRAW_BUFFER14 = 0x8833
const GL_DRAW_BUFFER15 = 0x8834
const GL_BLEND_EQUATION_ALPHA = 0x883D
const GL_POINT_SPRITE = 0x8861
const GL_COORD_REPLACE = 0x8862
const GL_MAX_VERTEX_ATTRIBS = 0x8869
const GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A
const GL_MAX_TEXTURE_COORDS = 0x8871
const GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872
const GL_FRAGMENT_SHADER = 0x8B30
const GL_VERTEX_SHADER = 0x8B31
const GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49
const GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A
const GL_MAX_VARYING_FLOATS = 0x8B4B
const GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C
const GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D
const GL_SHADER_TYPE = 0x8B4F
const GL_FLOAT_VEC2 = 0x8B50
const GL_FLOAT_VEC3 = 0x8B51
const GL_FLOAT_VEC4 = 0x8B52
const GL_INT_VEC2 = 0x8B53
const GL_INT_VEC3 = 0x8B54
const GL_INT_VEC4 = 0x8B55
const GL_BOOL = 0x8B56
const GL_BOOL_VEC2 = 0x8B57
const GL_BOOL_VEC3 = 0x8B58
const GL_BOOL_VEC4 = 0x8B59
const GL_FLOAT_MAT2 = 0x8B5A
const GL_FLOAT_MAT3 = 0x8B5B
const GL_FLOAT_MAT4 = 0x8B5C
const GL_SAMPLER_1D = 0x8B5D
const GL_SAMPLER_2D = 0x8B5E
const GL_SAMPLER_3D = 0x8B5F
const GL_SAMPLER_CUBE = 0x8B60
const GL_SAMPLER_1D_SHADOW = 0x8B61
const GL_SAMPLER_2D_SHADOW = 0x8B62
const GL_DELETE_STATUS = 0x8B80
const GL_COMPILE_STATUS = 0x8B81
const GL_LINK_STATUS = 0x8B82
const GL_VALIDATE_STATUS = 0x8B83
const GL_INFO_LOG_LENGTH = 0x8B84
const GL_ATTACHED_SHADERS = 0x8B85
const GL_ACTIVE_UNIFORMS = 0x8B86
const GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87
const GL_SHADER_SOURCE_LENGTH = 0x8B88
const GL_ACTIVE_ATTRIBUTES = 0x8B89
const GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A
const GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B
const GL_SHADING_LANGUAGE_VERSION = 0x8B8C
const GL_CURRENT_PROGRAM = 0x8B8D
const GL_POINT_SPRITE_COORD_ORIGIN = 0x8CA0
const GL_LOWER_LEFT = 0x8CA1
const GL_UPPER_LEFT = 0x8CA2
const GL_STENCIL_BACK_REF = 0x8CA3
const GL_STENCIL_BACK_VALUE_MASK = 0x8CA4
const GL_STENCIL_BACK_WRITEMASK = 0x8CA5


const GL_MULTISAMPLE = 0x809D
const GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E
const GL_SAMPLE_ALPHA_TO_ONE = 0x809F
const GL_SAMPLE_COVERAGE = 0x80A0
const GL_SAMPLE_BUFFERS = 0x80A8
const GL_SAMPLES = 0x80A9
const GL_SAMPLE_COVERAGE_VALUE = 0x80AA
const GL_SAMPLE_COVERAGE_INVERT = 0x80AB
const GL_CLAMP_TO_BORDER = 0x812D
const GL_TEXTURE0 = 0x84C0
const GL_TEXTURE1 = 0x84C1
const GL_TEXTURE2 = 0x84C2
const GL_TEXTURE3 = 0x84C3
const GL_TEXTURE4 = 0x84C4
const GL_TEXTURE5 = 0x84C5
const GL_TEXTURE6 = 0x84C6
const GL_TEXTURE7 = 0x84C7
const GL_TEXTURE8 = 0x84C8
const GL_TEXTURE9 = 0x84C9
const GL_TEXTURE10 = 0x84CA
const GL_TEXTURE11 = 0x84CB
const GL_TEXTURE12 = 0x84CC
const GL_TEXTURE13 = 0x84CD
const GL_TEXTURE14 = 0x84CE
const GL_TEXTURE15 = 0x84CF
const GL_TEXTURE16 = 0x84D0
const GL_TEXTURE17 = 0x84D1
const GL_TEXTURE18 = 0x84D2
const GL_TEXTURE19 = 0x84D3
const GL_TEXTURE20 = 0x84D4
const GL_TEXTURE21 = 0x84D5
const GL_TEXTURE22 = 0x84D6
const GL_TEXTURE23 = 0x84D7
const GL_TEXTURE24 = 0x84D8
const GL_TEXTURE25 = 0x84D9
const GL_TEXTURE26 = 0x84DA
const GL_TEXTURE27 = 0x84DB
const GL_TEXTURE28 = 0x84DC
const GL_TEXTURE29 = 0x84DD
const GL_TEXTURE30 = 0x84DE
const GL_TEXTURE31 = 0x84DF
const GL_ACTIVE_TEXTURE = 0x84E0
const GL_CLIENT_ACTIVE_TEXTURE = 0x84E1
const GL_MAX_TEXTURE_UNITS = 0x84E2
const GL_TRANSPOSE_MODELVIEW_MATRIX = 0x84E3
const GL_TRANSPOSE_PROJECTION_MATRIX = 0x84E4
const GL_TRANSPOSE_TEXTURE_MATRIX = 0x84E5
const GL_TRANSPOSE_COLOR_MATRIX = 0x84E6
const GL_SUBTRACT = 0x84E7
const GL_COMPRESSED_ALPHA = 0x84E9
const GL_COMPRESSED_LUMINANCE = 0x84EA
const GL_COMPRESSED_LUMINANCE_ALPHA = 0x84EB
const GL_COMPRESSED_INTENSITY = 0x84EC
const GL_COMPRESSED_RGB = 0x84ED
const GL_COMPRESSED_RGBA = 0x84EE
const GL_TEXTURE_COMPRESSION_HINT = 0x84EF
const GL_NORMAL_MAP = 0x8511
const GL_REFLECTION_MAP = 0x8512
const GL_TEXTURE_CUBE_MAP = 0x8513
const GL_TEXTURE_BINDING_CUBE_MAP = 0x8514
const GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515
const GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516
const GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517
const GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518
const GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519
const GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A
const GL_PROXY_TEXTURE_CUBE_MAP = 0x851B
const GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C
const GL_COMBINE = 0x8570
const GL_COMBINE_RGB = 0x8571
const GL_COMBINE_ALPHA = 0x8572
const GL_RGB_SCALE = 0x8573
const GL_ADD_SIGNED = 0x8574
const GL_INTERPOLATE = 0x8575
const GL_CONSTANT = 0x8576
const GL_PRIMARY_COLOR = 0x8577
const GL_PREVIOUS = 0x8578
const GL_SOURCE0_RGB = 0x8580
const GL_SOURCE1_RGB = 0x8581
const GL_SOURCE2_RGB = 0x8582
const GL_SOURCE0_ALPHA = 0x8588
const GL_SOURCE1_ALPHA = 0x8589
const GL_SOURCE2_ALPHA = 0x858A
const GL_OPERAND0_RGB = 0x8590
const GL_OPERAND1_RGB = 0x8591
const GL_OPERAND2_RGB = 0x8592
const GL_OPERAND0_ALPHA = 0x8598
const GL_OPERAND1_ALPHA = 0x8599
const GL_OPERAND2_ALPHA = 0x859A
const GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0
const GL_TEXTURE_COMPRESSED = 0x86A1
const GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2
const GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3
const GL_DOT3_RGB = 0x86AE
const GL_DOT3_RGBA = 0x86AF
const GL_MULTISAMPLE_BIT = 0x20000000


const GL_BLEND_DST_RGB = 0x80C8
const GL_BLEND_SRC_RGB = 0x80C9
const GL_BLEND_DST_ALPHA = 0x80CA
const GL_BLEND_SRC_ALPHA = 0x80CB
const GL_POINT_SIZE_MIN = 0x8126
const GL_POINT_SIZE_MAX = 0x8127
const GL_POINT_FADE_THRESHOLD_SIZE = 0x8128
const GL_POINT_DISTANCE_ATTENUATION = 0x8129
const GL_GENERATE_MIPMAP = 0x8191
const GL_GENERATE_MIPMAP_HINT = 0x8192
const GL_DEPTH_COMPONENT16 = 0x81A5
const GL_DEPTH_COMPONENT24 = 0x81A6
const GL_DEPTH_COMPONENT32 = 0x81A7
const GL_MIRRORED_REPEAT = 0x8370
const GL_FOG_COORDINATE_SOURCE = 0x8450
const GL_FOG_COORDINATE = 0x8451
const GL_FRAGMENT_DEPTH = 0x8452
const GL_CURRENT_FOG_COORDINATE = 0x8453
const GL_FOG_COORDINATE_ARRAY_TYPE = 0x8454
const GL_FOG_COORDINATE_ARRAY_STRIDE = 0x8455
const GL_FOG_COORDINATE_ARRAY_POINTER = 0x8456
const GL_FOG_COORDINATE_ARRAY = 0x8457
const GL_COLOR_SUM = 0x8458
const GL_CURRENT_SECONDARY_COLOR = 0x8459
const GL_SECONDARY_COLOR_ARRAY_SIZE = 0x845A
const GL_SECONDARY_COLOR_ARRAY_TYPE = 0x845B
const GL_SECONDARY_COLOR_ARRAY_STRIDE = 0x845C
const GL_SECONDARY_COLOR_ARRAY_POINTER = 0x845D
const GL_SECONDARY_COLOR_ARRAY = 0x845E
const GL_MAX_TEXTURE_LOD_BIAS = 0x84FD
const GL_TEXTURE_FILTER_CONTROL = 0x8500
const GL_TEXTURE_LOD_BIAS = 0x8501
const GL_INCR_WRAP = 0x8507
const GL_DECR_WRAP = 0x8508
const GL_TEXTURE_DEPTH_SIZE = 0x884A
const GL_DEPTH_TEXTURE_MODE = 0x884B
const GL_TEXTURE_COMPARE_MODE = 0x884C
const GL_TEXTURE_COMPARE_FUNC = 0x884D
const GL_COMPARE_R_TO_TEXTURE = 0x884E


const GL_CURRENT_FOG_COORD = 0x8453
const GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING = 0x889D
const GL_FOG_COORD = GL_FOG_COORDINATE
const GL_FOG_COORD_ARRAY = GL_FOG_COORDINATE_ARRAY
const GL_FOG_COORD_ARRAY_BUFFER_BINDING = GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
const GL_FOG_COORD_ARRAY_POINTER = GL_FOG_COORDINATE_ARRAY_POINTER
const GL_FOG_COORD_ARRAY_STRIDE = GL_FOG_COORDINATE_ARRAY_STRIDE
const GL_FOG_COORD_ARRAY_TYPE = GL_FOG_COORDINATE_ARRAY_TYPE
const GL_FOG_COORD_SRC = GL_FOG_COORDINATE_SOURCE
const GL_SRC0_ALPHA = GL_SOURCE0_ALPHA
const GL_SRC0_RGB = GL_SOURCE0_RGB
const GL_SRC1_ALPHA = GL_SOURCE1_ALPHA
const GL_SRC1_RGB = GL_SOURCE1_RGB
const GL_SRC2_ALPHA = GL_SOURCE2_ALPHA
const GL_SRC2_RGB = GL_SOURCE2_RGB
const GL_BUFFER_SIZE = 0x8764
const GL_BUFFER_USAGE = 0x8765
const GL_QUERY_COUNTER_BITS = 0x8864
const GL_CURRENT_QUERY = 0x8865
const GL_QUERY_RESULT = 0x8866
const GL_QUERY_RESULT_AVAILABLE = 0x8867
const GL_ARRAY_BUFFER = 0x8892
const GL_ELEMENT_ARRAY_BUFFER = 0x8893
const GL_ARRAY_BUFFER_BINDING = 0x8894
const GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895
const GL_VERTEX_ARRAY_BUFFER_BINDING = 0x8896
const GL_NORMAL_ARRAY_BUFFER_BINDING = 0x8897
const GL_COLOR_ARRAY_BUFFER_BINDING = 0x8898
const GL_INDEX_ARRAY_BUFFER_BINDING = 0x8899
const GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889A
const GL_EDGE_FLAG_ARRAY_BUFFER_BINDING = 0x889B
const GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING = 0x889C

const GL_WEIGHT_ARRAY_BUFFER_BINDING = 0x889E
const GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F
const GL_READ_ONLY = 0x88B8
const GL_WRITE_ONLY = 0x88B9
const GL_READ_WRITE = 0x88BA
const GL_BUFFER_ACCESS = 0x88BB
const GL_BUFFER_MAPPED = 0x88BC
const GL_BUFFER_MAP_POINTER = 0x88BD
const GL_STREAM_DRAW = 0x88E0
const GL_STREAM_READ = 0x88E1
const GL_STREAM_COPY = 0x88E2
const GL_STATIC_DRAW = 0x88E4
const GL_STATIC_READ = 0x88E5
const GL_STATIC_COPY = 0x88E6
const GL_DYNAMIC_DRAW = 0x88E8
const GL_DYNAMIC_READ = 0x88E9
const GL_DYNAMIC_COPY = 0x88EA
const GL_SAMPLES_PASSED = 0x8914

