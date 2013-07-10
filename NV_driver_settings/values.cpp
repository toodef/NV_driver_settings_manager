#include "main.h"

nv_api::value_id_opt_t nv_api::get_value_id_from_value_name( NvU32 setting_id, string const & value_name )
{
   dword_map_t::iterator it = dword_settings_map_.find(setting_id);

   if (it == dword_settings_map_.end())
      return boost::none;

   if (it->second.left.find(value_name) != it->second.left.end())
      return it->second.left.at(value_name);

   NvAPI_UnicodeString setting_name;

   NvAPI_DRS_GetSettingNameFromId(setting_id, &setting_name);

   string setting_str_name = NvUS_to_string(setting_name);

   cout << "this value name(" << value_name << ")" << " not exist in this setting('" << setting_str_name
        << "', " << setting_id << ")" << endl
        << "name may be one of: ";

   print_optional_values(it, cout);

   cout << endl;

   return boost::none;
}

nv_api::value_name_opt_t nv_api::get_value_name_from_value_id( NvU32 setting_id, unsigned int value_id )
{
   dword_map_t::iterator const it = dword_settings_map_.find(setting_id);

   if (it == dword_settings_map_.end())
      return boost::none;

   if (it->second.right.find(value_id) != it->second.right.end())
      return it->second.right.at(value_id);

   NvAPI_UnicodeString setting_name;

   NvAPI_DRS_GetSettingNameFromId(setting_id, &setting_name);

   string setting_str_name = NvUS_to_string(setting_name);

   cout << "this value id(" << value_id << ") "<< " not exist in this setting('" << setting_str_name
        << "', " << setting_id << ")" << endl
        << "id may be one of: ";

   print_optional_id(it, cout);

   cout << endl;

   return boost::none;
}

void nv_api::init_map()
{
   //"Antialiasing - Line gamma"
   dword_settings_map_[OGL_AA_LINE_GAMMA_ID] = list_of<rel_t>("DISABLED", OGL_AA_LINE_GAMMA_DISABLED)
                                                             ("ENABLED" , OGL_AA_LINE_GAMMA_ENABLED )
                                                             ("MIN"     , OGL_AA_LINE_GAMMA_MIN     )
                                                             ("MAX"     , OGL_AA_LINE_GAMMA_MAX     )
                                                             ;

   //"Deep color for 3D applications"
   dword_settings_map_[OGL_DEEP_COLOR_SCANOUT_ID] = list_of<rel_t>("DISABLE", OGL_DEEP_COLOR_SCANOUT_DISABLE)
                                                                  ("ENABLE" , OGL_DEEP_COLOR_SCANOUT_ENABLE )
                                                                  ;

   //"Controls the number of vblank signals from the display to wait before rendering a frame (SwapInterval) on OpenGL. In order to force VSYNC ON or OFF, use VSYNCMODE."
   dword_settings_map_[OGL_DEFAULT_SWAP_INTERVAL_ID] = list_of<rel_t>("TEAR"          , OGL_DEFAULT_SWAP_INTERVAL_TEAR          )
                                                                     ("VSYNC_ONE"     , OGL_DEFAULT_SWAP_INTERVAL_VSYNC_ONE     )
                                                                     ("VSYNC"         , OGL_DEFAULT_SWAP_INTERVAL_VSYNC         )
                                                                     ("VALUE_MASK"    , OGL_DEFAULT_SWAP_INTERVAL_VALUE_MASK    )
                                                                     ("FORCE_MASK"    , OGL_DEFAULT_SWAP_INTERVAL_FORCE_MASK    )
                                                                     ("FORCE_OFF"     , OGL_DEFAULT_SWAP_INTERVAL_FORCE_OFF     )
                                                                     ("FORCE_ON"      , OGL_DEFAULT_SWAP_INTERVAL_FORCE_ON      )
                                                                     ("APP_CONTROLLED", OGL_DEFAULT_SWAP_INTERVAL_APP_CONTROLLED)
                                                                     ("DISABLE"       , OGL_DEFAULT_SWAP_INTERVAL_DISABLE       )
                                                                     ;

   //"Controls if we evaluate the current scan line for a (un)synced flip with negative intervals. A value in the range of 0 - 100%"
   dword_settings_map_[OGL_DEFAULT_SWAP_INTERVAL_FRACTIONAL_ID] = list_of<rel_t>("ZERO_SCANLINES"             , OGL_DEFAULT_SWAP_INTERVAL_FRACTIONAL_ZERO_SCANLINES             )
                                                                                ("ONE_FULL_FRAME_OF_SCANLINES", OGL_DEFAULT_SWAP_INTERVAL_FRACTIONAL_ONE_FULL_FRAME_OF_SCANLINES)
                                                                                ;

   //"Controls if the number of SwapIntervals set is treated as negative or positive values on OpenGL."
   dword_settings_map_[OGL_DEFAULT_SWAP_INTERVAL_SIGN_ID] = list_of<rel_t>("POSITIVE", OGL_DEFAULT_SWAP_INTERVAL_SIGN_POSITIVE)
                                                                          ("NEGATIVE", OGL_DEFAULT_SWAP_INTERVAL_SIGN_NEGATIVE)
                                                                          ;

   //"Event Log Severity Threshold. This controls which events are logged."
   dword_settings_map_[OGL_EVENT_LOG_SEVERITY_THRESHOLD_ID] = list_of<rel_t>("DISABLE"    , OGL_EVENT_LOG_SEVERITY_THRESHOLD_DISABLE    )
                                                                            ("CRITICAL"   , OGL_EVENT_LOG_SEVERITY_THRESHOLD_CRITICAL   )
                                                                            ("WARNING"    , OGL_EVENT_LOG_SEVERITY_THRESHOLD_WARNING    )
                                                                            ("INFORMATION", OGL_EVENT_LOG_SEVERITY_THRESHOLD_INFORMATION)
                                                                            ("ALL"        , OGL_EVENT_LOG_SEVERITY_THRESHOLD_ALL        )
                                                                            ;

   //"Buffer-flipping mode"
   dword_settings_map_[OGL_FORCE_BLIT_ID] = list_of<rel_t>("ON" , OGL_FORCE_BLIT_ON )
                                                          ("OFF", OGL_FORCE_BLIT_OFF)
                                                          ;

   //"Force Stereo shuttering"
   dword_settings_map_[OGL_FORCE_STEREO_ID] = list_of<rel_t>("OFF", OGL_FORCE_STEREO_OFF)
                                                            ("ON" , OGL_FORCE_STEREO_ON )
                                                            ;



   //"Multi-display/mixed-GPU acceleration"
   dword_settings_map_[OGL_MULTIMON_ID] = list_of<rel_t>("SINGLE_MONITOR"         , OGL_MULTIMON_SINGLE_MONITOR         )
                                                        ("COMPATIBILITY_LCD"      , OGL_MULTIMON_COMPATIBILITY_LCD      )
                                                        ("COMPATIBILITY_GCD"      , OGL_MULTIMON_COMPATIBILITY_GCD      )
                                                        ("PERFORMANCE_LCD"        , OGL_MULTIMON_PERFORMANCE_LCD        )
                                                        ("PERFORMANCE_GCD"        , OGL_MULTIMON_PERFORMANCE_GCD        )
                                                        ("EXTENDED_SINGLE_MONITOR", OGL_MULTIMON_EXTENDED_SINGLE_MONITOR)
                                                        ("PERFORMANCE_QUADRO"     , OGL_MULTIMON_PERFORMANCE_QUADRO     )
                                                        ("MULTIMON_BUFFER"        , OGL_MULTIMON_MULTIMON_BUFFER        )
                                                        ;

   //"Exported Overlay pixel types"
   dword_settings_map_[OGL_OVERLAY_PIXEL_TYPE_ID] = list_of<rel_t>("NONE"       , OGL_OVERLAY_PIXEL_TYPE_NONE       )
                                                                  ("CI"         , OGL_OVERLAY_PIXEL_TYPE_CI         )
                                                                  ("RGBA"       , OGL_OVERLAY_PIXEL_TYPE_RGBA       )
                                                                  ("CI_AND_RGBA", OGL_OVERLAY_PIXEL_TYPE_CI_AND_RGBA)
                                                                  ;

   //"Enable overlay"
   dword_settings_map_[OGL_OVERLAY_SUPPORT_ID] = list_of<rel_t>("OFF"     , OGL_OVERLAY_SUPPORT_OFF     )
                                                               ("ON"      , OGL_OVERLAY_SUPPORT_ON      )
                                                               ("FORCE_SW", OGL_OVERLAY_SUPPORT_FORCE_SW)
                                                               ;

   //"High level control of the rendering quality on OpenGL"
   dword_settings_map_[OGL_QUALITY_ENHANCEMENTS_ID] = list_of<rel_t>("HQUAL", OGL_QUALITY_ENHANCEMENTS_HQUAL)
                                                                    ("QUAL" , OGL_QUALITY_ENHANCEMENTS_QUAL )
                                                                    ("PERF" , OGL_QUALITY_ENHANCEMENTS_PERF )
                                                                    ("HPERF", OGL_QUALITY_ENHANCEMENTS_HPERF)
                                                                    ;

   //"Unified back/depth buffer"
   dword_settings_map_[OGL_SINGLE_BACKDEPTH_BUFFER_ID] = list_of<rel_t>("DISABLE"       , OGL_SINGLE_BACKDEPTH_BUFFER_DISABLE       )
                                                                       ("ENABLE"        , OGL_SINGLE_BACKDEPTH_BUFFER_ENABLE        )
                                                                       ("USE_HW_DEFAULT", OGL_SINGLE_BACKDEPTH_BUFFER_USE_HW_DEFAULT)
                                                                       ;

   //"Threaded optimization"
   dword_settings_map_[OGL_THREAD_CONTROL_ID] = list_of<rel_t>("ENABLE"          , OGL_THREAD_CONTROL_ENABLE          )
                                                              ("DISABLE"         , OGL_THREAD_CONTROL_DISABLE         )
                                                              ("DUMP_STATS"      , OGL_THREAD_CONTROL_DUMP_STATS      )
                                                              ("IGNORE_GET_ERROR", OGL_THREAD_CONTROL_IGNORE_GET_ERROR)
                                                              ("AUTO"            , 0                                  )
                                                              ;

   //"Triple buffering"
   dword_settings_map_[OGL_TRIPLE_BUFFER_ID] = list_of<rel_t>("DISABLE", OGL_TRIPLE_BUFFER_DISABLED)
                                                             ("ENABLE" , OGL_TRIPLE_BUFFER_ENABLED )
                                                             ;


   //"controls video-editing mode for OpenGL"
   dword_settings_map_[OGL_VIDEO_EDITING_MODE_ID] = list_of<rel_t>("DISABLE", OGL_VIDEO_EDITING_MODE_DISABLE)
                                                                  ("ENABLE" , OGL_VIDEO_EDITING_MODE_ENABLE )
                                                                  ;

   //"Antialiasing - Behavior Flags"
   dword_settings_map_[AA_BEHAVIOR_FLAGS_ID] = list_of<rel_t>("NONE"                                  , AA_BEHAVIOR_FLAGS_NONE                                  )
                                                             ("TREAT_OVERRIDE_AS_APP_CONTROLLED"      , AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_APP_CONTROLLED      )
                                                             ("TREAT_OVERRIDE_AS_ENHANCE"             , AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_ENHANCE             )
                                                             ("DISABLE_OVERRIDE"                      , AA_BEHAVIOR_FLAGS_DISABLE_OVERRIDE                      )
                                                             ("TREAT_ENHANCE_AS_APP_CONTROLLED"       , AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_APP_CONTROLLED       )
                                                             ("TREAT_ENHANCE_AS_OVERRIDE"             , AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_OVERRIDE             )
                                                             ("DISABLE_ENHANCE"                       , AA_BEHAVIOR_FLAGS_DISABLE_ENHANCE                       )
                                                             ("MAP_VCAA_TO_MULTISAMPLING"             , AA_BEHAVIOR_FLAGS_MAP_VCAA_TO_MULTISAMPLING             )
                                                             ("SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING", AA_BEHAVIOR_FLAGS_SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING)
                                                             ("DISABLE_CPLAA"                         , AA_BEHAVIOR_FLAGS_DISABLE_CPLAA                         )
                                                             ("SKIP_RT_DIM_CHECK_FOR_ENHANCE"         , AA_BEHAVIOR_FLAGS_SKIP_RT_DIM_CHECK_FOR_ENHANCE         )
                                                             ("DISABLE_SLIAA"                         , AA_BEHAVIOR_FLAGS_DISABLE_SLIAA                         )
                                                             ("DEFAULT"                               , AA_BEHAVIOR_FLAGS_DEFAULT                               )
                                                             ("AA_RT_BPP_DIV_4"                       , AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4                       )
                                                             ("AA_RT_BPP_DIV_4_SHIFT"                 , AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4_SHIFT                 )
                                                             ("NON_AA_RT_BPP_DIV_4"                   , AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4                   )
                                                             ("NON_AA_RT_BPP_DIV_4_SHIFT"             , AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4_SHIFT             )
                                                             ("MASK"                                  , AA_BEHAVIOR_FLAGS_MASK                                  )
                                                             ;

   //"Antialiasing - Transparency Multisampling"
   dword_settings_map_[AA_MODE_ALPHATOCOVERAGE_ID] = list_of<rel_t>("MASK", AA_MODE_ALPHATOCOVERAGE_MODE_MASK)
                                                                   ("OFF" , AA_MODE_ALPHATOCOVERAGE_MODE_OFF )
                                                                   ("ON"  , AA_MODE_ALPHATOCOVERAGE_MODE_ON  )
                                                                   ("MAX" , AA_MODE_ALPHATOCOVERAGE_MODE_MAX )
                                                                   ;

   //"Antialiasing - Gamma correction"
   dword_settings_map_[AA_MODE_GAMMACORRECTION_ID] = list_of<rel_t>("MASK"         , AA_MODE_GAMMACORRECTION_MASK         )
                                                                   ("OFF"          , AA_MODE_GAMMACORRECTION_OFF          )
                                                                   ("ON_IF_FOS"    , AA_MODE_GAMMACORRECTION_ON_IF_FOS    )
                                                                   ("ON_ALWAYS"    , AA_MODE_GAMMACORRECTION_ON_ALWAYS    )
                                                                   ("MAX"          , AA_MODE_GAMMACORRECTION_MAX          )
                                                                   ("DEFAULT"      , AA_MODE_GAMMACORRECTION_DEFAULT      )
                                                                   ("DEFAULT_TESLA", AA_MODE_GAMMACORRECTION_DEFAULT_TESLA)
                                                                   ("DEFAULT_FERMI", AA_MODE_GAMMACORRECTION_DEFAULT_FERMI)
                                                                   ;

   //"Antialiasing - Setting"
   dword_settings_map_[AA_MODE_METHOD_ID] = list_of<rel_t>("NONE"                            , AA_MODE_METHOD_NONE                            )
                                                          ("SUPERSAMPLE_2X_H"                , AA_MODE_METHOD_SUPERSAMPLE_2X_H                )
                                                          ("SUPERSAMPLE_2X_V"                , AA_MODE_METHOD_SUPERSAMPLE_2X_V                )
                                                          ("SUPERSAMPLE_1_5X1_5"             , AA_MODE_METHOD_SUPERSAMPLE_1_5X1_5             )
                                                          ("FREE_0x03"                       , AA_MODE_METHOD_FREE_0x03                       )
                                                          ("FREE_0x04"                       , AA_MODE_METHOD_FREE_0x04                       )
                                                          ("SUPERSAMPLE_4X"                  , AA_MODE_METHOD_SUPERSAMPLE_4X                  )
                                                          ("SUPERSAMPLE_4X_BIAS"             , AA_MODE_METHOD_SUPERSAMPLE_4X_BIAS             )
                                                          ("SUPERSAMPLE_4X_GAUSSIAN"         , AA_MODE_METHOD_SUPERSAMPLE_4X_GAUSSIAN         )
                                                          ("FREE_0x08"                       , AA_MODE_METHOD_FREE_0x08                       )
                                                          ("FREE_0x09"                       , AA_MODE_METHOD_FREE_0x09                       )
                                                          ("SUPERSAMPLE_9X"                  , AA_MODE_METHOD_SUPERSAMPLE_9X                  )
                                                          ("SUPERSAMPLE_9X_BIAS"             , AA_MODE_METHOD_SUPERSAMPLE_9X_BIAS             )
                                                          ("SUPERSAMPLE_16X"                 , AA_MODE_METHOD_SUPERSAMPLE_16X                 )
                                                          ("SUPERSAMPLE_16X_BIAS"            , AA_MODE_METHOD_SUPERSAMPLE_16X_BIAS            )
                                                          ("MULTISAMPLE_2X_DIAGONAL"         , AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL         )
                                                          ("MULTISAMPLE_2X_QUINCUNX"         , AA_MODE_METHOD_MULTISAMPLE_2X_QUINCUNX         )
                                                          ("MULTISAMPLE_4X"                  , AA_MODE_METHOD_MULTISAMPLE_4X                  )
                                                          ("FREE_0x11"                       , AA_MODE_METHOD_FREE_0x11                       )
                                                          ("MULTISAMPLE_4X_GAUSSIAN"         , AA_MODE_METHOD_MULTISAMPLE_4X_GAUSSIAN         )
                                                          ("MIXEDSAMPLE_4X_SKEWED_4TAP"      , AA_MODE_METHOD_MIXEDSAMPLE_4X_SKEWED_4TAP      )
                                                          ("FREE_0x14"                       , AA_MODE_METHOD_FREE_0x14                       )
                                                          ("FREE_0x15"                       , AA_MODE_METHOD_FREE_0x15                       )
                                                          ("MIXEDSAMPLE_6X"                  , AA_MODE_METHOD_MIXEDSAMPLE_6X                  )
                                                          ("MIXEDSAMPLE_6X_SKEWED_6TAP"      , AA_MODE_METHOD_MIXEDSAMPLE_6X_SKEWED_6TAP      )
                                                          ("MIXEDSAMPLE_8X"                  , AA_MODE_METHOD_MIXEDSAMPLE_8X                  )
                                                          ("MIXEDSAMPLE_8X_SKEWED_8TAP"      , AA_MODE_METHOD_MIXEDSAMPLE_8X_SKEWED_8TAP      )
                                                          ("MIXEDSAMPLE_16X"                 , AA_MODE_METHOD_MIXEDSAMPLE_16X                 )
                                                          ("MULTISAMPLE_4X_GAMMA"            , AA_MODE_METHOD_MULTISAMPLE_4X_GAMMA            )
                                                          ("MULTISAMPLE_16X"                 , AA_MODE_METHOD_MULTISAMPLE_16X                 )
                                                          ("VCAA_32X_8v24"                   , AA_MODE_METHOD_VCAA_32X_8v24                   )
                                                          ("CORRUPTION_CHECK"                , AA_MODE_METHOD_CORRUPTION_CHECK                )
                                                          ("6X_CT"                           , AA_MODE_METHOD_6X_CT                           )
                                                          ("MULTISAMPLE_2X_DIAGONAL_GAMMA"   , AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_GAMMA   )
                                                          ("SUPERSAMPLE_4X_GAMMA"            , AA_MODE_METHOD_SUPERSAMPLE_4X_GAMMA            )
                                                          ("MULTISAMPLE_4X_FOSGAMMA"         , AA_MODE_METHOD_MULTISAMPLE_4X_FOSGAMMA         )
                                                          ("MULTISAMPLE_2X_DIAGONAL_FOSGAMMA", AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA)
                                                          ("SUPERSAMPLE_4X_FOSGAMMA"         , AA_MODE_METHOD_SUPERSAMPLE_4X_FOSGAMMA         )
                                                          ("MULTISAMPLE_8X"                  , AA_MODE_METHOD_MULTISAMPLE_8X                  )
                                                          ("VCAA_8X_4v4"                     , AA_MODE_METHOD_VCAA_8X_4v4                     )
                                                          ("VCAA_16X_4v12"                   , AA_MODE_METHOD_VCAA_16X_4v12                   )
                                                          ("VCAA_16X_8v8"                    , AA_MODE_METHOD_VCAA_16X_8v8                    )
                                                          ("MIXEDSAMPLE_32X"                 , AA_MODE_METHOD_MIXEDSAMPLE_32X                 )
                                                          ("SUPERVCAA_64X_4v12"              , AA_MODE_METHOD_SUPERVCAA_64X_4v12              )
                                                          ("SUPERVCAA_64X_8v8"               , AA_MODE_METHOD_SUPERVCAA_64X_8v8               )
                                                          ("MIXEDSAMPLE_64X"                 , AA_MODE_METHOD_MIXEDSAMPLE_64X                 )
                                                          ("MIXEDSAMPLE_128X"                , AA_MODE_METHOD_MIXEDSAMPLE_128X                )
                                                          ("COUNT"                           , AA_MODE_METHOD_COUNT                           )
                                                          ("METHOD_MASK"                     , AA_MODE_METHOD_METHOD_MASK                     )
                                                          ("METHOD_MAX"                      , AA_MODE_METHOD_METHOD_MAX                      )
                                                          ;

   //"Antialiasing - Transparency Supersampling"
   dword_settings_map_[AA_MODE_REPLAY_ID] = list_of<rel_t>("SAMPLES_MASK"              , AA_MODE_REPLAY_SAMPLES_MASK              )
                                                          ("SAMPLES_ONE"               , AA_MODE_REPLAY_SAMPLES_ONE               )
                                                          ("SAMPLES_TWO"               , AA_MODE_REPLAY_SAMPLES_TWO               )
                                                          ("SAMPLES_FOUR"              , AA_MODE_REPLAY_SAMPLES_FOUR              )
                                                          ("SAMPLES_EIGHT"             , AA_MODE_REPLAY_SAMPLES_EIGHT             )
                                                          ("SAMPLES_MAX"               , AA_MODE_REPLAY_SAMPLES_MAX               )
                                                          ("MODE_MASK"                 , AA_MODE_REPLAY_MODE_MASK                 )
                                                          ("MODE_OFF"                  , AA_MODE_REPLAY_MODE_OFF                  )
                                                          ("MODE_ALPHA_TEST"           , AA_MODE_REPLAY_MODE_ALPHA_TEST           )
                                                          ("MODE_PIXEL_KILL"           , AA_MODE_REPLAY_MODE_PIXEL_KILL           )
                                                          ("MODE_DYN_BRANCH"           , AA_MODE_REPLAY_MODE_DYN_BRANCH           )
                                                          ("MODE_OPTIMAL"              , AA_MODE_REPLAY_MODE_OPTIMAL              )
                                                          ("MODE_ALL"                  , AA_MODE_REPLAY_MODE_ALL                  )
                                                          ("MODE_MAX"                  , AA_MODE_REPLAY_MODE_MAX                  )
                                                          ("TRANSPARENCY"              , AA_MODE_REPLAY_TRANSPARENCY              )
                                                          ("DISALLOW_TRAA"             , AA_MODE_REPLAY_DISALLOW_TRAA             )
                                                          ("TRANSPARENCY_DEFAULT"      , AA_MODE_REPLAY_TRANSPARENCY_DEFAULT      )
                                                          ("TRANSPARENCY_DEFAULT_TESLA", AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA)
                                                          ("TRANSPARENCY_DEFAULT_FERMI", AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI)
                                                          ;

   //"Antialiasing - Mode"
   dword_settings_map_[AA_MODE_SELECTOR_ID] = list_of<rel_t>("MASK"       , AA_MODE_SELECTOR_MASK       )
                                                            ("APP_CONTROL", AA_MODE_SELECTOR_APP_CONTROL)
                                                            ("OVERRIDE"   , AA_MODE_SELECTOR_OVERRIDE   )
                                                            ("ENHANCE"    , AA_MODE_SELECTOR_ENHANCE    )
                                                            ("MAX"        , AA_MODE_SELECTOR_MAX        )
                                                            ;

   //"Antialiasing - SLI AA"
   dword_settings_map_[AA_MODE_SELECTOR_SLIAA_ID] = list_of<rel_t>("DISABLED", AA_MODE_SELECTOR_SLIAA_DISABLED)
                                                                  ("ENABLED" , AA_MODE_SELECTOR_SLIAA_ENABLED )
                                                                  ;

   //"Anisotropic filtering setting"
   dword_settings_map_[ANISO_MODE_LEVEL_ID] = list_of<rel_t>("MASK"       , ANISO_MODE_LEVEL_MASK       )
                                                            ("NONE_POINT" , ANISO_MODE_LEVEL_NONE_POINT )
                                                            ("NONE_LINEAR", ANISO_MODE_LEVEL_NONE_LINEAR)
                                                            ("MAX"        , ANISO_MODE_LEVEL_MAX        )
                                                            ;

   //"Anisotropic filtering mode"
   dword_settings_map_[ANISO_MODE_SELECTOR_ID] = list_of<rel_t>("MASK", ANISO_MODE_SELECTOR_MASK)
                                                               ("APP" , ANISO_MODE_SELECTOR_APP )
                                                               ("USER", ANISO_MODE_SELECTOR_USER)
                                                               ("COND", ANISO_MODE_SELECTOR_COND)
                                                               ("MAX" , ANISO_MODE_SELECTOR_MAX )
                                                               ;

   //"Application Profile Notification Popup Timeout"
   dword_settings_map_[APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ID] = list_of<rel_t>("DISABLED"       , APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_DISABLED       )
                                                                                    ("NINE_SECONDS"   , APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_NINE_SECONDS   )
                                                                                    ("FIFTEEN_SECONDS", APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_FIFTEEN_SECONDS)
                                                                                    ("THIRTY_SECONDS" , APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_THIRTY_SECONDS )
                                                                                    ("ONE_MINUTE"     , APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ONE_MINUTE     )
                                                                                    ("TWO_MINUTE"     , APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_TWO_MINUTES    )
                                                                                    ;

   //"Do not display this profile in the Control Panel"
   dword_settings_map_[CPL_HIDDEN_PROFILE_ID] = list_of<rel_t>("DISABLED", CPL_HIDDEN_PROFILE_DISABLED)
                                                              ("ENABLED" , CPL_HIDDEN_PROFILE_ENABLED )
                                                              ;

   //"Export Performance Counters"
   dword_settings_map_[EXPORT_PERF_COUNTERS_ID] = list_of<rel_t>("OFF", EXPORT_PERF_COUNTERS_OFF)
                                                                ("ON" , EXPORT_PERF_COUNTERS_ON )
                                                                ;

   //"NVIDIA Predefined FXAA Usage"
   dword_settings_map_[FXAA_ALLOW_ID] = list_of<rel_t>("DISALLOWED", FXAA_ALLOW_DISALLOWED)
                                                      ("ALLOWED"   , FXAA_ALLOW_ALLOWED   )
                                                      ;

   //"Toggle FXAA on or off"
   dword_settings_map_[FXAA_ENABLE_ID] = list_of<rel_t>("OFF", FXAA_ENABLE_OFF)
                                                       ("ON" , FXAA_ENABLE_ON )
                                                       ;

   //"Toggle FXAA Indicator on or off"
   dword_settings_map_[FXAA_INDICATOR_ENABLE_ID] = list_of<rel_t>("OFF", FXAA_INDICATOR_ENABLE_OFF)
                                                                 ("ON" , FXAA_INDICATOR_ENABLE_ON )
                                                                 ;

   //"Show the SLI on-screen indicator"
   dword_settings_map_[MCSFRSHOWSPLIT_ID] = list_of<rel_t>("DISABLED", MCSFRSHOWSPLIT_DISABLED)
                                                          ("ENABLED" , MCSFRSHOWSPLIT_ENABLED )
                                                          ("AUTO"    , 0                      )
                                                          ;

   //"Debug bits for optimus"
   dword_settings_map_[OPTIMUS_DEBUG_ID] = list_of<rel_t>("RENDER_TRANSPORT" , OPTIMUS_DEBUG_NULL_RENDER_TRANSPORT )
                                                         ("DISPLAY_TRANSPORT", OPTIMUS_DEBUG_NULL_DISPLAY_TRANSPORT)
                                                         ("AUTO"             , 0                                   )
                                                         ;

   //"Maximum AA samples allowed for a given application"
   dword_settings_map_[OPTIMUS_MAXAA_ID] = list_of<rel_t>("MIN", OPTIMUS_MAXAA_MIN)
                                                         ("MAX", OPTIMUS_MAXAA_MAX)
                                                         ;

   //"Display the PhysX indicator"
   dword_settings_map_[PHYSXINDICATOR_ID] = list_of<rel_t>("DISABLED", PHYSXINDICATOR_DISABLED)
                                                          ("ENABLED" , PHYSXINDICATOR_ENABLED )
                                                          ("AUTO"    , 0                      )
                                                          ;

   //"Power management mode"
   dword_settings_map_[PREFERRED_PSTATE_ID] = list_of<rel_t>("ADAPTIVE"  , PREFERRED_PSTATE_ADAPTIVE         )
                                                            ("PREFER_MAX", PREFERRED_PSTATE_PREFER_MAX       )
                                                            ("CONTROLLED", PREFERRED_PSTATE_DRIVER_CONTROLLED)
                                                            ("PREFER_MIN", PREFERRED_PSTATE_PREFER_MIN       )
                                                            ("MIN"       , PREFERRED_PSTATE_MIN              )
                                                            ("MAX"       , PREFERRED_PSTATE_MAX              )
                                                            ;

   //"Frame Rate Limiter"
   dword_settings_map_[PS_FRAMERATE_LIMITER_ID] = list_of<rel_t>("DISABLED"            , PS_FRAMERATE_LIMITER_DISABLED            )
                                                                ("FPS_20"              , PS_FRAMERATE_LIMITER_FPS_20              )
                                                                ("FPS_30"              , PS_FRAMERATE_LIMITER_FPS_30              )
                                                                ("FPS_40"              , PS_FRAMERATE_LIMITER_FPS_40              )
                                                                ("FPSMASK"             , PS_FRAMERATE_LIMITER_FPSMASK             )
                                                                ("GPS_WEB"             , PS_FRAMERATE_LIMITER_GPS_WEB             )
                                                                ("FORCE_OPTIMUS_POLICY", PS_FRAMERATE_LIMITER_FORCE_OPTIMUS_POLICY)
                                                                ("DISALLOWED"          , PS_FRAMERATE_LIMITER_DISALLOWED          )
                                                                ("THRESHOLD"           , PS_FRAMERATE_LIMITER_THRESHOLD           )
                                                                ("TEMPERATURE"         , PS_FRAMERATE_LIMITER_TEMPERATURE         )
                                                                ("POWER"               , PS_FRAMERATE_LIMITER_POWER               )
                                                                ("MODEMASK"            , PS_FRAMERATE_LIMITER_MODEMASK            )
                                                                ("ACCURATE"            , PS_FRAMERATE_LIMITER_ACCURATE            )
                                                                ("ALLOW_WINDOWED"      , PS_FRAMERATE_LIMITER_ALLOW_WINDOWED      )
                                                                ("FORCEON"             , PS_FRAMERATE_LIMITER_FORCEON             )
                                                                ("ENABLED"             , PS_FRAMERATE_LIMITER_ENABLED             )
                                                                ("MASK"                , PS_FRAMERATE_LIMITER_MASK                )
                                                                ;

   //"iGPU transcoding"
   dword_settings_map_[SHIM_IGPU_TRANSCODING_ID] = list_of<rel_t>("DISABLE", SHIM_IGPU_TRANSCODING_DISABLE)
                                                                 ("ENABLE" , SHIM_IGPU_TRANSCODING_ENABLE )
                                                                 ;

   //"Optimus flags for enabled applications"
   dword_settings_map_[SHIM_MCCOMPAT_ID] = list_of<rel_t>("INTEGRATED"   , SHIM_MCCOMPAT_INTEGRATED   )
                                                         ("ENABLE"       , SHIM_MCCOMPAT_ENABLE       )
                                                         ("USER_EDITABLE", SHIM_MCCOMPAT_USER_EDITABLE)
                                                         ("MASK"         , SHIM_MCCOMPAT_MASK         )
                                                         ("VIDEO_MASK"   , SHIM_MCCOMPAT_VIDEO_MASK   )
                                                         ("VARYING_BIT"  , SHIM_MCCOMPAT_VARYING_BIT  )
                                                         ("AUTO_SELECT"  , SHIM_MCCOMPAT_AUTO_SELECT  )
                                                         ("OVERRIDE_BIT" , SHIM_MCCOMPAT_OVERRIDE_BIT )
                                                         ;

   //"Enable application for Optimus"
   dword_settings_map_[SHIM_RENDERING_MODE_ID] = list_of<rel_t>("INTEGRATED"   , SHIM_RENDERING_MODE_INTEGRATED   )
                                                               ("ENABLE"       , SHIM_RENDERING_MODE_ENABLE       )
                                                               ("USER_EDITABLE", SHIM_RENDERING_MODE_USER_EDITABLE)
                                                               ("MASK"         , SHIM_RENDERING_MODE_MASK         )
                                                               ("VIDEO_MASK"   , SHIM_RENDERING_MODE_VIDEO_MASK   )
                                                               ("VARYING_BIT"  , SHIM_RENDERING_MODE_VARYING_BIT  )
                                                               ("AUTO_SELECT"  , SHIM_RENDERING_MODE_AUTO_SELECT  )
                                                               ("OVERRIDE_BIT" , SHIM_RENDERING_MODE_OVERRIDE_BIT )
                                                               ;

   //"Shim Rendering Mode Options per application for Optimus"
   dword_settings_map_[SHIM_RENDERING_OPTIONS_ID] = list_of<rel_t>("DEFAULT_RENDERING_MODE"    , SHIM_RENDERING_OPTIONS_DEFAULT_RENDERING_MODE    )
                                                                  ("DISABLE_ASYNC_PRESENT"     , SHIM_RENDERING_OPTIONS_DISABLE_ASYNC_PRESENT     )
                                                                  ("EHSHELL_DETECT"            , SHIM_RENDERING_OPTIONS_EHSHELL_DETECT            )
                                                                  ("FLASHPLAYER_HOST_DETECT"   , SHIM_RENDERING_OPTIONS_FLASHPLAYER_HOST_DETECT   )
                                                                  ("VIDEO_DRM_APP_DETECT"      , SHIM_RENDERING_OPTIONS_VIDEO_DRM_APP_DETECT      )
                                                                  ("IGNORE_OVERRIDES"          , SHIM_RENDERING_OPTIONS_IGNORE_OVERRIDES          )
                                                                  ("CHILDPROCESS_DETECT"       , SHIM_RENDERING_OPTIONS_CHILDPROCESS_DETECT       )
                                                                  ("ENABLE_DWM_ASYNC_PRESENT"  , SHIM_RENDERING_OPTIONS_ENABLE_DWM_ASYNC_PRESENT  )
                                                                  ("PARENTPROCESS_DETECT"      , SHIM_RENDERING_OPTIONS_PARENTPROCESS_DETECT      )
                                                                  ("ALLOW_INHERITANCE"         , SHIM_RENDERING_OPTIONS_ALLOW_INHERITANCE         )
                                                                  ("DISABLE_WRAPPERS"          , SHIM_RENDERING_OPTIONS_DISABLE_WRAPPERS          )
                                                                  ("DISABLE_DXGI_WRAPPERS"     , SHIM_RENDERING_OPTIONS_DISABLE_DXGI_WRAPPERS     )
                                                                  ("PRUNE_UNSUPPORTED_FORMATS" , SHIM_RENDERING_OPTIONS_PRUNE_UNSUPPORTED_FORMATS )
                                                                  ("ENABLE_ALPHA_FORMAT"       , SHIM_RENDERING_OPTIONS_ENABLE_ALPHA_FORMAT       )
                                                                  ("IGPU_TRANSCODING"          , SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING          )
                                                                  ("DISABLE_CUDA"              , SHIM_RENDERING_OPTIONS_DISABLE_CUDA              )
                                                                  ("ALLOW_CP_CAPS_FOR_VIDEO"   , SHIM_RENDERING_OPTIONS_ALLOW_CP_CAPS_FOR_VIDEO   )
                                                                  ("ENABLE_NEW_HOOKING"        , SHIM_RENDERING_OPTIONS_ENABLE_NEW_HOOKING        )
                                                                  ("DISABLE_DURING_SECURE_BOOT", SHIM_RENDERING_OPTIONS_DISABLE_DURING_SECURE_BOOT)
                                                                  ;

   //"Number of GPUs to use on SLI rendering mode"
   dword_settings_map_[SLI_GPU_COUNT_ID] = list_of<rel_t>("AUTOSELECT", SLI_GPU_COUNT_AUTOSELECT)
                                                         ("ONE"       , SLI_GPU_COUNT_ONE       )
                                                         ("TWO"       , SLI_GPU_COUNT_TWO       )
                                                         ("THREE"     , SLI_GPU_COUNT_THREE     )
                                                         ("FOUR"      , SLI_GPU_COUNT_FOUR      )
                                                         ;

   //"NVIDIA predefined number of GPUs to use on SLI rendering mode"
   dword_settings_map_[SLI_PREDEFINED_GPU_COUNT_ID] = list_of<rel_t>("AUTOSELECT", SLI_PREDEFINED_GPU_COUNT_AUTOSELECT)
                                                                    ("ONE"       , SLI_PREDEFINED_GPU_COUNT_ONE       )
                                                                    ("TWO"       , SLI_PREDEFINED_GPU_COUNT_TWO       )
                                                                    ("THREE"     , SLI_PREDEFINED_GPU_COUNT_THREE     )
                                                                    ("FOUR"      , SLI_PREDEFINED_GPU_COUNT_FOUR      )
                                                                    ;

   //"NVIDIA predefined number of GPUs to use on SLI rendering mode on DirectX 10"
   dword_settings_map_[SLI_PREDEFINED_GPU_COUNT_DX10_ID] = list_of<rel_t>("AUTOSELECT", SLI_PREDEFINED_GPU_COUNT_DX10_AUTOSELECT)
                                                                         ("ONE"       , SLI_PREDEFINED_GPU_COUNT_DX10_ONE       )
                                                                         ("TWO"       , SLI_PREDEFINED_GPU_COUNT_DX10_TWO       )
                                                                         ("THREE"     , SLI_PREDEFINED_GPU_COUNT_DX10_THREE     )
                                                                         ("FOUR"      , SLI_PREDEFINED_GPU_COUNT_DX10_FOUR      )
                                                                         ;

   //"NVIDIA predefined SLI mode"
   dword_settings_map_[SLI_PREDEFINED_MODE_ID] = list_of<rel_t>("AUTOSELECT"                     , SLI_PREDEFINED_MODE_AUTOSELECT                     )
                                                               ("FORCE_SINGLE"                   , SLI_PREDEFINED_MODE_FORCE_SINGLE                   )
                                                               ("FORCE_AFR"                      , SLI_PREDEFINED_MODE_FORCE_AFR                      )
                                                               ("FORCE_AFR2"                     , SLI_PREDEFINED_MODE_FORCE_AFR2                     )
                                                               ("FORCE_SFR"                      , SLI_PREDEFINED_MODE_FORCE_SFR                      )
                                                               ("FORCE_AFR_OF_SFR__FALLBACK_3AFR", SLI_PREDEFINED_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR)
                                                               ;

   //"NVIDIA predefined SLI mode on DirectX 10"
   dword_settings_map_[SLI_PREDEFINED_MODE_DX10_ID] = list_of<rel_t>("AUTOSELECT"                     , SLI_PREDEFINED_MODE_DX10_AUTOSELECT                     )
                                                                    ("FORCE_SINGLE"                   , SLI_PREDEFINED_MODE_DX10_FORCE_SINGLE                   )
                                                                    ("FORCE_AFR"                      , SLI_PREDEFINED_MODE_DX10_FORCE_AFR                      )
                                                                    ("FORCE_AFR2"                     , SLI_PREDEFINED_MODE_DX10_FORCE_AFR2                     )
                                                                    ("FORCE_SFR"                      , SLI_PREDEFINED_MODE_DX10_FORCE_SFR                      )
                                                                    ("FORCE_AFR_OF_SFR__FALLBACK_3AFR", SLI_PREDEFINED_MODE_DX10_FORCE_AFR_OF_SFR__FALLBACK_3AFR)
                                                                    ;

   //"SLI rendering mode"
   dword_settings_map_[SLI_RENDERING_MODE_ID] = list_of<rel_t>("AUTOSELECT"                     , SLI_RENDERING_MODE_AUTOSELECT                     )
                                                              ("FORCE_SINGLE"                   , SLI_RENDERING_MODE_FORCE_SINGLE                   )
                                                              ("FORCE_AFR"                      , SLI_RENDERING_MODE_FORCE_AFR                      )
                                                              ("FORCE_AFR2"                     , SLI_RENDERING_MODE_FORCE_AFR2                     )
                                                              ("FORCE_SFR"                      , SLI_RENDERING_MODE_FORCE_SFR                      )
                                                              ("FORCE_AFR_OF_SFR__FALLBACK_3AFR", SLI_RENDERING_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR)
                                                              ;

   //"Flag to control smooth AFR behavior"
   dword_settings_map_[VSYNCSMOOTHAFR_ID] = list_of<rel_t>("OFF", VSYNCSMOOTHAFR_OFF)
                                                          ("ON" , VSYNCSMOOTHAFR_ON )
                                                          ;

   //"Vsync - Behavior Flags"
   dword_settings_map_[VSYNC_BEHAVIOR_FLAGS_ID] = list_of<rel_t>("NONE"                        , VSYNC_BEHAVIOR_FLAGS_NONE                        )
                                                                ("DEFAULT"                     , VSYNC_BEHAVIOR_FLAGS_DEFAULT                     )
                                                                ("IGNORE_FLIPINTERVAL_MULTIPLE", VSYNC_BEHAVIOR_FLAGS_IGNORE_FLIPINTERVAL_MULTIPLE)
                                                                ;

   //"Stereo - Swap eyes"
   dword_settings_map_[WKS_API_STEREO_EYES_EXCHANGE_ID] = list_of<rel_t>("OFF", WKS_API_STEREO_EYES_EXCHANGE_OFF)
                                                                        ("ON" , WKS_API_STEREO_EYES_EXCHANGE_ON )
                                                                        ;

   //"Stereo - Display mode"
   dword_settings_map_[WKS_API_STEREO_MODE_ID] = list_of<rel_t>("SHUTTER_GLASSES"             , WKS_API_STEREO_MODE_SHUTTER_GLASSES)
                                                               ("VERTICAL_INTERLACED"         , WKS_API_STEREO_MODE_VERTICAL_INTERLACED)
                                                               ("TWINVIEW"                    , WKS_API_STEREO_MODE_TWINVIEW)
                                                               ("NV17_SHUTTER_GLASSES_AUTO"   , WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO)
                                                               ("NV17_SHUTTER_GLASSES_DAC0"   , WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0)
                                                               ("NV17_SHUTTER_GLASSES_DAC1"   , WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1)
                                                               ("COLOR_LINE"                  , WKS_API_STEREO_MODE_COLOR_LINE)
                                                               ("COLOR_INTERLEAVED"           , WKS_API_STEREO_MODE_COLOR_INTERLEAVED)
                                                               ("ANAGLYPH"                    , WKS_API_STEREO_MODE_ANAGLYPH)
                                                               ("HORIZONTAL_INTERLACED"       , WKS_API_STEREO_MODE_HORIZONTAL_INTERLACED)
                                                               ("SIDE_FIELD"                  , WKS_API_STEREO_MODE_SIDE_FIELD)
                                                               ("SUB_FIELD"                   , WKS_API_STEREO_MODE_SUB_FIELD)
                                                               ("CHECKERBOARD"                , WKS_API_STEREO_MODE_CHECKERBOARD)
                                                               ("INVERSE_CHECKERBOARD"        , WKS_API_STEREO_MODE_INVERSE_CHECKERBOARD)
                                                               ("TRIDELITY_SL"                , WKS_API_STEREO_MODE_TRIDELITY_SL)
                                                               ("TRIDELITY_MV"                , WKS_API_STEREO_MODE_TRIDELITY_MV)
                                                               ("SEEFRONT"                    , WKS_API_STEREO_MODE_SEEFRONT)
                                                               ("STEREO_MIRROR"               , WKS_API_STEREO_MODE_STEREO_MIRROR)
                                                               ("FRAME_SEQUENTIAL"            , WKS_API_STEREO_MODE_FRAME_SEQUENTIAL)
                                                               ("AUTODETECT_PASSIVE_MODE"     , WKS_API_STEREO_MODE_AUTODETECT_PASSIVE_MODE)
                                                               ("AEGIS_DT_FRAME_SEQUENTIAL"   , WKS_API_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL)
                                                               ("OEM_EMITTER_FRAME_SEQUENTIAL", WKS_API_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL)
                                                               ("USE_HW_DEFAULT"              , WKS_API_STEREO_MODE_USE_HW_DEFAULT)
                                                               ("DEFAULT_GL"                  , WKS_API_STEREO_MODE_DEFAULT_GL)
                                                               ;

   //"Stereo - Win8 support"
   dword_settings_map_[WKS_FEATURE_SUPPORT_CONTROL_ID] = list_of<rel_t>("OFF"                          , WKS_FEATURE_SUPPORT_CONTROL_OFF                          )
                                                                       ("SRS_1714_WIN8_STEREO"         , WKS_FEATURE_SUPPORT_CONTROL_SRS_1714_WIN8_STEREO         )
                                                                       ("WIN8_STEREO_EXPORT_IF_ENABLED", WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_EXPORT_IF_ENABLED)
                                                                       ;

   //"Stereo - Dongle Support"
   dword_settings_map_[WKS_STEREO_DONGLE_SUPPORT_ID] = list_of<rel_t>("OFF", WKS_STEREO_DONGLE_SUPPORT_OFF)
                                                                     ("DAC", WKS_STEREO_DONGLE_SUPPORT_DAC)
                                                                     ("DLP", WKS_STEREO_DONGLE_SUPPORT_DLP)
                                                                     ;

   //"Stereo - Enable"
   dword_settings_map_[WKS_STEREO_SUPPORT_ID] = list_of<rel_t>("OFF", WKS_STEREO_SUPPORT_OFF)
                                                              ("ON" , WKS_STEREO_SUPPORT_ON )
                                                              ;

   //"Ambient Occlusion"
   dword_settings_map_[AO_MODE_ID] = list_of<rel_t>("OFF"   , AO_MODE_OFF   )
                                                   ("LOW"   , AO_MODE_LOW   )
                                                   ("MEDIUM", AO_MODE_MEDIUM)
                                                   ("HIGH"  , AO_MODE_HIGH  )
                                                   ;

   //"NVIDIA Predefined Ambient Occlusion Usage"
   dword_settings_map_[AO_MODE_ACTIVE_ID] = list_of<rel_t>("DISABLED", AO_MODE_ACTIVE_DISABLED)
                                                          ("ENABLED" , AO_MODE_ACTIVE_ENABLED )
                                                          ;

   //"Texture filtering - Driver Controlled LOD Bias"
   dword_settings_map_[AUTO_LODBIASADJUST_ID] = list_of<rel_t>("OFF", AUTO_LODBIASADJUST_OFF)
                                                              ("ON" , AUTO_LODBIASADJUST_ON )
                                                              ;

   //"Texture filtering - LOD Bias"
   dword_settings_map_[LODBIASADJUST_ID] = list_of<rel_t>("OFF", AUTO_LODBIASADJUST_OFF)
                                                         ("ON" , AUTO_LODBIASADJUST_ON)
                                                         ;

   //"Maximum pre-rendered frames"
   dword_settings_map_[PRERENDERLIMIT_ID] = list_of<rel_t>("MIN"           , PRERENDERLIMIT_MIN           )
                                                          ("MAX"           , PRERENDERLIMIT_MAX           )
                                                          ("APP_CONTROLLED", PRERENDERLIMIT_APP_CONTROLLED)
                                                          ;

   //"Dynamic tiling"
   dword_settings_map_[PS_DYNAMIC_TILING_ID] = list_of<rel_t>("OFF", PS_DYNAMIC_TILING_OFF)
                                                             ("ON" , PS_DYNAMIC_TILING_ON )
                                                             ;

   //"Texture filtering - Anisotropic sample optimization"
   dword_settings_map_[PS_TEXFILTER_ANISO_OPTS2_ID] = list_of<rel_t>("OFF", PS_TEXFILTER_ANISO_OPTS2_OFF)
                                                                    ("ON" , PS_TEXFILTER_ANISO_OPTS2_ON )
                                                                    ;

   //"Texture filtering - Anisotropic filter optimization"
   dword_settings_map_[PS_TEXFILTER_BILINEAR_IN_ANISO_ID] = list_of<rel_t>("OFF", PS_TEXFILTER_BILINEAR_IN_ANISO_OFF)
                                                                          ("ON" , PS_TEXFILTER_BILINEAR_IN_ANISO_ON )
                                                                          ;

   //"Texture filtering - Trilinear optimization"
   dword_settings_map_[PS_TEXFILTER_DISABLE_TRILIN_SLOPE_ID] = list_of<rel_t>("OFF", PS_TEXFILTER_DISABLE_TRILIN_SLOPE_OFF)
                                                                             ("ON" , PS_TEXFILTER_DISABLE_TRILIN_SLOPE_ON )
                                                                             ;

   //"Texture filtering - Negative LOD bias"
   dword_settings_map_[PS_TEXFILTER_NO_NEG_LODBIAS_ID] = list_of<rel_t>("OFF", PS_TEXFILTER_NO_NEG_LODBIAS_OFF)
                                                                       ("ON" , PS_TEXFILTER_NO_NEG_LODBIAS_ON )
                                                                       ;

   //"Texture filtering - Quality"
   dword_settings_map_[QUALITY_ENHANCEMENTS_ID] = list_of<rel_t>("HIGHQUALITY"    , QUALITY_ENHANCEMENTS_HIGHQUALITY    )
                                                                ("QUALITY"        , QUALITY_ENHANCEMENTS_QUALITY        )
                                                                ("PERFORMANCE"    , QUALITY_ENHANCEMENTS_PERFORMANCE    )
                                                                ("HIGHPERFORMANCE", QUALITY_ENHANCEMENTS_HIGHPERFORMANCE)
                                                                ;

   //"Preferred refresh rate"
   dword_settings_map_[REFRESH_RATE_OVERRIDE_ID] = list_of<rel_t>("APPLICATION_CONTROLLED", REFRESH_RATE_OVERRIDE_APPLICATION_CONTROLLED)
                                                                 ("HIGHEST_AVAILABLE"     , REFRESH_RATE_OVERRIDE_HIGHEST_AVAILABLE     )
                                                                 ;

   //"PowerThrottle"
   dword_settings_map_[SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_ID] = list_of<rel_t>("OFF", SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_OFF)
                                                                                  ("ON" , SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_ON )
                                                                                  ;

   //"VAB Default Data"
   dword_settings_map_[SET_VAB_DATA_ID] = list_of<rel_t>("ZERO"            , SET_VAB_DATA_ZERO            )
                                                        ("UINT_ONE"        , SET_VAB_DATA_UINT_ONE        )
                                                        ("FLOAT_ONE"       , SET_VAB_DATA_FLOAT_ONE       )
                                                        ("FLOAT_POS_INF"   , SET_VAB_DATA_FLOAT_POS_INF   )
                                                        ("FLOAT_NAN"       , SET_VAB_DATA_FLOAT_NAN       )
                                                        ("USE_API_DEFAULTS", SET_VAB_DATA_USE_API_DEFAULTS)
                                                        ;

   //"Vertical Sync"
   dword_settings_map_[VSYNCMODE_ID] = list_of<rel_t>("PASSIVE"      , VSYNCMODE_PASSIVE      )
                                                     ("FORCEOFF"     , VSYNCMODE_FORCEOFF     )
                                                     ("FORCEON"      , VSYNCMODE_FORCEON      )
                                                     ("FLIPINTERVAL2", VSYNCMODE_FLIPINTERVAL2)
                                                     ("FLIPINTERVAL3", VSYNCMODE_FLIPINTERVAL3)
                                                     ("FLIPINTERVAL4", VSYNCMODE_FLIPINTERVAL4)
                                                     ;

   //"Vertical Sync Tear Control"
   dword_settings_map_[VSYNCTEARCONTROL_ID] = list_of<rel_t>("DISABLE", VSYNCTEARCONTROL_DISABLE)
                                                            ("ENABLE", VSYNCTEARCONTROL_ENABLE)
                                                            ;
}
