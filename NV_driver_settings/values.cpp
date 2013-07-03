#include "main.h"

unsigned int nv_api::get_value_id_from_str( string const & setting_name, string const & value_name )
{
   if (setting_name == "Antialiasing - Line gamma")
   {
      if (value_name == "DISABLED")
         return OGL_AA_LINE_GAMMA_DISABLED;
      else if (value_name == "ENABLED")
         return OGL_AA_LINE_GAMMA_ENABLED;
      else if (value_name == "MIN")
         return OGL_AA_LINE_GAMMA_MIN;
      else if (value_name == "MAX")
         return OGL_AA_LINE_GAMMA_MAX;
   }
   else if (setting_name == "Deep color for 3D applications")
   {
      if (value_name == "DISABLE")
         return OGL_DEEP_COLOR_SCANOUT_DISABLE;
      else if (value_name == "ENABLE")
         return OGL_DEEP_COLOR_SCANOUT_ENABLE;
   }
   else if (setting_name == "Controls the number of vblank signals from the display to wait before rendering a frame (SwapInterval) on OpenGL. In order to force VSYNC ON or OFF, use VSYNCMODE.")
   {
      if (value_name == "TEAR")
         return OGL_DEFAULT_SWAP_INTERVAL_TEAR;
      else if (value_name == "VSYNC_ONE")
         return OGL_DEFAULT_SWAP_INTERVAL_VSYNC_ONE;
      else if (value_name == "VSYNC")
         return OGL_DEFAULT_SWAP_INTERVAL_VSYNC;
      else if (value_name == "VALUE_MASK")
         return OGL_DEFAULT_SWAP_INTERVAL_VALUE_MASK;
      else if (value_name == "FORCE_MASK")
         return OGL_DEFAULT_SWAP_INTERVAL_FORCE_MASK;
      else if (value_name == "FORCE_OFF")
         return OGL_DEFAULT_SWAP_INTERVAL_FORCE_OFF;
      else if (value_name == "FORCE_ON")
         return OGL_DEFAULT_SWAP_INTERVAL_FORCE_ON;
      else if (value_name == "APP_CONTROLLED")
         return OGL_DEFAULT_SWAP_INTERVAL_APP_CONTROLLED;
      else if (value_name == "DISABLE")
         return OGL_DEFAULT_SWAP_INTERVAL_DISABLE;
   }
   else if (setting_name == "Controls if we evaluate the current scan line for a (un)synced flip with negative intervals. A value in the range of 0 - 100%")
   {
      if (value_name == "ZERO_SCANLINES")
         return OGL_DEFAULT_SWAP_INTERVAL_FRACTIONAL_ZERO_SCANLINES;
      else if (value_name == "ONE_FULL_FRAME_OF_SCANLINES")
         return OGL_DEFAULT_SWAP_INTERVAL_FRACTIONAL_ONE_FULL_FRAME_OF_SCANLINES;
   }
   else if (setting_name == "Controls if the number of SwapIntervals set is treated as negative or positive values on OpenGL.")
   {
      if (value_name == "POSITIVE")
         return OGL_DEFAULT_SWAP_INTERVAL_SIGN_POSITIVE;
      else if (value_name == "NEGATIVE")
         return OGL_DEFAULT_SWAP_INTERVAL_SIGN_NEGATIVE;
   }
   else if (setting_name == "Event Log Severity Threshold. This controls which events are logged.")
   {
      if (value_name == "DISABLE")
         return OGL_EVENT_LOG_SEVERITY_THRESHOLD_DISABLE;
      else if (value_name == "CRITICAL")
         return OGL_EVENT_LOG_SEVERITY_THRESHOLD_CRITICAL;
      else if (value_name == "WARNING")
         return OGL_EVENT_LOG_SEVERITY_THRESHOLD_WARNING;
      else if (value_name == "INFORMATION")
         return OGL_EVENT_LOG_SEVERITY_THRESHOLD_INFORMATION;
      else if (value_name == "ALL")
         return OGL_EVENT_LOG_SEVERITY_THRESHOLD_ALL;
   }
   else if (setting_name == "Buffer-flipping mode")
   {
      if (value_name == "ON")
         return OGL_FORCE_BLIT_ON;
      else if (value_name == "OFF")
         return OGL_FORCE_BLIT_OFF;
   }
   else if (setting_name == "Force Stereo shuttering")
   {
      if (value_name == "OFF")
         return OGL_FORCE_STEREO_OFF;
      else if (value_name == "ON")
         return OGL_FORCE_BLIT_ON;
   }
   else if (setting_name == "Multi-display/mixed-GPU acceleration")
   {
      if (value_name == "SINGLE_MONITOR")
         return OGL_MULTIMON_SINGLE_MONITOR;
      else if (value_name == "COMPATIBILITY_LCD")
         return OGL_MULTIMON_COMPATIBILITY_LCD;
      else if (value_name == "COMPATIBILITY_GCD")
         return OGL_MULTIMON_COMPATIBILITY_GCD;
      else if (value_name == "PERFORMANCE_LCD")
         return OGL_MULTIMON_PERFORMANCE_LCD;
      else if (value_name == "PERFORMANCE_GCD")
         return OGL_MULTIMON_PERFORMANCE_GCD;
      else if (value_name == "EXTENDED_SINGLE_MONITOR")
         return OGL_MULTIMON_EXTENDED_SINGLE_MONITOR;
      else if (value_name == "PERFORMANCE_QUADRO")
         return OGL_MULTIMON_PERFORMANCE_QUADRO;
      else if (value_name == "MULTIMON_BUFFER")
         return OGL_MULTIMON_MULTIMON_BUFFER;
   }
   else if (setting_name == "Exported Overlay pixel types")
   {
      if (value_name == "NONE")
         return OGL_OVERLAY_PIXEL_TYPE_NONE;
      else if (value_name == "CI")
         return OGL_OVERLAY_PIXEL_TYPE_CI;
      else if (value_name == "RGBA")
         return OGL_OVERLAY_PIXEL_TYPE_RGBA;
      else if (value_name == "CI_AND_RGBA")
         return OGL_OVERLAY_PIXEL_TYPE_CI_AND_RGBA;
   }
   else if (setting_name == "Enable overlay")
   {
      if (value_name == "OFF")
         return OGL_OVERLAY_SUPPORT_OFF;
      else if (value_name == "ON")
         return OGL_OVERLAY_SUPPORT_ON;
      else if (value_name == "FORCE_SW")
         return OGL_OVERLAY_SUPPORT_FORCE_SW;
   }
   else if (setting_name == "High level control of the rendering quality on OpenGL")
   {
      if (value_name == "HQUAL")
         return OGL_QUALITY_ENHANCEMENTS_HQUAL;
      else if (value_name == "QUAL")
         return OGL_QUALITY_ENHANCEMENTS_QUAL;
      else if (value_name == "PERF")
         return OGL_QUALITY_ENHANCEMENTS_PERF;
      else if (value_name == "HPERF")
         return OGL_QUALITY_ENHANCEMENTS_HPERF;
   }
   else if (setting_name == "Unified back/depth buffer")
   {
      if (value_name == "DISABLE")
         return OGL_SINGLE_BACKDEPTH_BUFFER_DISABLE;
      else if (value_name == "ENABLE")
         return OGL_SINGLE_BACKDEPTH_BUFFER_ENABLE;
      else if (value_name == "USE_HW_DEFAULT")
         return OGL_SINGLE_BACKDEPTH_BUFFER_USE_HW_DEFAULT;
   }
   else if (setting_name == "Threaded optimization")
   {
      if (value_name == "ENABLE")
         return OGL_THREAD_CONTROL_ENABLE;
      else if (value_name == "DISABLE")
         return OGL_THREAD_CONTROL_DISABLE;
      else if (value_name == "DUMP_STATS")
         return OGL_THREAD_CONTROL_DUMP_STATS;
      else if (value_name == "IGNORE_GET_ERROR")
         return OGL_THREAD_CONTROL_IGNORE_GET_ERROR;
   }
   else if (setting_name == "Triple buffering")
   {
      if (value_name == "DISABLE")
         return OGL_TRIPLE_BUFFER_DISABLED;
      else if (value_name == "ENABLE")
         return OGL_TRIPLE_BUFFER_ENABLED;
   }
   else if (setting_name == "controls video-editing mode for OpenGL")
   {
      if (value_name == "DISABLE")
         return OGL_VIDEO_EDITING_MODE_DISABLE;
      else if (value_name == "ENABLE")
         return OGL_VIDEO_EDITING_MODE_ENABLE;
   }
   else if (setting_name == "Antialiasing - Behavior Flags")
   {
      if (value_name == "NONE")
         return AA_BEHAVIOR_FLAGS_NONE;
      else if (value_name == "TREAT_OVERRIDE_AS_APP_CONTROLLED")
         return AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_APP_CONTROLLED;
      else if (value_name == "TREAT_OVERRIDE_AS_ENHANCE")
         return AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_ENHANCE;
      else if (value_name == "DISABLE_OVERRIDE")
         return AA_BEHAVIOR_FLAGS_DISABLE_OVERRIDE;
      else if (value_name == "TREAT_ENHANCE_AS_APP_CONTROLLED")
         return AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_APP_CONTROLLED;
      else if (value_name == "TREAT_ENHANCE_AS_OVERRIDE")
         return AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_OVERRIDE;
      else if (value_name == "DISABLE_ENHANCE")
         return AA_BEHAVIOR_FLAGS_DISABLE_ENHANCE;
      else if (value_name == "MAP_VCAA_TO_MULTISAMPLING")
         return AA_BEHAVIOR_FLAGS_MAP_VCAA_TO_MULTISAMPLING;
      else if (value_name == "SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING")
         return AA_BEHAVIOR_FLAGS_SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING;
      else if (value_name == "DISABLE_CPLAA")
         return AA_BEHAVIOR_FLAGS_DISABLE_CPLAA;
      else if (value_name == "SKIP_RT_DIM_CHECK_FOR_ENHANCE")
         return AA_BEHAVIOR_FLAGS_SKIP_RT_DIM_CHECK_FOR_ENHANCE;
      else if (value_name == "DISABLE_SLIAA")
         return AA_BEHAVIOR_FLAGS_DISABLE_SLIAA;
      else if (value_name == "DEFAULT")
         return AA_BEHAVIOR_FLAGS_DEFAULT;
      else if (value_name == "AA_RT_BPP_DIV_4")
         return AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4;
      else if (value_name == "AA_RT_BPP_DIV_4_SHIFT")
         return AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4_SHIFT;
      else if (value_name == "NON_AA_RT_BPP_DIV_4")
         return AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4;
      else if (value_name == "NON_AA_RT_BPP_DIV_4_SHIFT")
         return AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4_SHIFT;
      else if (value_name == "MASK")
         return AA_BEHAVIOR_FLAGS_MASK;
   }
   else if (setting_name == "Antialiasing - Transparency Multisampling")
   {
      if (value_name == "MASK")
         return AA_MODE_ALPHATOCOVERAGE_MODE_MASK;
      else if (value_name == "OFF")
         return AA_MODE_ALPHATOCOVERAGE_MODE_OFF;
      else if (value_name == "ON")
         return AA_MODE_ALPHATOCOVERAGE_MODE_ON;
      else if (value_name == "MAX")
         return AA_MODE_ALPHATOCOVERAGE_MODE_MAX;
   }
   else if (setting_name == "Antialiasing - Gamma correction")
   {
      if (value_name == "MASK")
         return AA_MODE_GAMMACORRECTION_MASK;
      else if (value_name == "OFF")
         return AA_MODE_GAMMACORRECTION_OFF;
      else if (value_name == "ON_IF_FOS")
         return AA_MODE_GAMMACORRECTION_ON_IF_FOS;
      else if (value_name == "ON_ALWAYS")
         return AA_MODE_GAMMACORRECTION_ON_ALWAYS;
      else if (value_name == "MAX")
         return AA_MODE_GAMMACORRECTION_MAX;
      else if (value_name == "DEFAULT")
         return AA_MODE_GAMMACORRECTION_DEFAULT;
      else if (value_name == "DEFAULT_TESLA")
         return AA_MODE_GAMMACORRECTION_DEFAULT_TESLA;
      else if (value_name == "DEFAULT_FERMI")
         return AA_MODE_GAMMACORRECTION_DEFAULT_FERMI;
   }
   else if (setting_name == "Antialiasing - Setting")
   {
      if (value_name == "NONE")
         return AA_MODE_METHOD_NONE;
      else if (value_name == "SUPERSAMPLE_2X_H")
         return AA_MODE_METHOD_SUPERSAMPLE_2X_H;
      else if (value_name == "SUPERSAMPLE_2X_V")
         return AA_MODE_METHOD_SUPERSAMPLE_2X_V;
      else if (value_name == "SUPERSAMPLE_1_5X1_5")
         return AA_MODE_METHOD_SUPERSAMPLE_1_5X1_5;
      else if (value_name == "FREE_0x03")
         return AA_MODE_METHOD_FREE_0x03;
      else if (value_name == "FREE_0x04")
         return AA_MODE_METHOD_FREE_0x04;
      else if (value_name == "SUPERSAMPLE_4X")
         return AA_MODE_METHOD_SUPERSAMPLE_4X;
      else if (value_name == "SUPERSAMPLE_4X_BIAS")
         return AA_MODE_METHOD_SUPERSAMPLE_4X_BIAS;
      else if (value_name == "SUPERSAMPLE_4X_GAUSSIAN")
         return AA_MODE_METHOD_SUPERSAMPLE_4X_GAUSSIAN;
      else if (value_name == "FREE_0x08")
         return AA_MODE_METHOD_FREE_0x08;
      else if (value_name == "FREE_0x09")
         return AA_MODE_METHOD_FREE_0x09;
      else if (value_name == "SUPERSAMPLE_9X")
         return AA_MODE_METHOD_SUPERSAMPLE_9X;
      else if (value_name == "SUPERSAMPLE_9X_BIAS")
         return AA_MODE_METHOD_SUPERSAMPLE_9X_BIAS;
      else if (value_name == "SUPERSAMPLE_16X")
         return AA_MODE_METHOD_SUPERSAMPLE_16X;
      else if (value_name == "SUPERSAMPLE_16X_BIAS")
         return AA_MODE_METHOD_SUPERSAMPLE_16X_BIAS;
      else if (value_name == "MULTISAMPLE_2X_DIAGONAL")
         return AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL;
      else if (value_name == "MULTISAMPLE_2X_QUINCUNX")
         return AA_MODE_METHOD_MULTISAMPLE_2X_QUINCUNX;
      else if (value_name == "MULTISAMPLE_4X")
         return AA_MODE_METHOD_MULTISAMPLE_4X;
      else if (value_name == "FREE_0x11")
         return AA_MODE_METHOD_FREE_0x11;
      else if (value_name == "MULTISAMPLE_4X_GAUSSIAN")
         return AA_MODE_METHOD_MULTISAMPLE_4X_GAUSSIAN;
      else if (value_name == "MIXEDSAMPLE_4X_SKEWED_4TAP")
         return AA_MODE_METHOD_MIXEDSAMPLE_4X_SKEWED_4TAP;
      else if (value_name == "FREE_0x14")
         return AA_MODE_METHOD_FREE_0x14;
      else if (value_name == "FREE_0x15")
         return AA_MODE_METHOD_FREE_0x15;
      else if (value_name == "MIXEDSAMPLE_6X")
         return AA_MODE_METHOD_MIXEDSAMPLE_6X;
      else if (value_name == "MIXEDSAMPLE_6X_SKEWED_6TAP")
         return AA_MODE_METHOD_MIXEDSAMPLE_6X_SKEWED_6TAP;
      else if (value_name == "MIXEDSAMPLE_8X")
         return AA_MODE_METHOD_MIXEDSAMPLE_8X;
      else if (value_name == "MIXEDSAMPLE_8X_SKEWED_8TAP")
         return AA_MODE_METHOD_MIXEDSAMPLE_8X_SKEWED_8TAP;
      else if (value_name == "MIXEDSAMPLE_16X")
         return AA_MODE_METHOD_MIXEDSAMPLE_16X;
      else if (value_name == "MULTISAMPLE_4X_GAMMA")
         return AA_MODE_METHOD_MULTISAMPLE_4X_GAMMA;
      else if (value_name == "MULTISAMPLE_16X")
         return AA_MODE_METHOD_MULTISAMPLE_16X;
      else if (value_name == "VCAA_32X_8v24")
         return AA_MODE_METHOD_VCAA_32X_8v24;
      else if (value_name == "CORRUPTION_CHECK")
         return AA_MODE_METHOD_CORRUPTION_CHECK;
      else if (value_name == "6X_CT")
         return AA_MODE_METHOD_6X_CT;
      else if (value_name == "MULTISAMPLE_2X_DIAGONAL_GAMMA")
         return AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_GAMMA;
      else if (value_name == "SUPERSAMPLE_4X_GAMMA")
         return AA_MODE_METHOD_SUPERSAMPLE_4X_GAMMA;
      else if (value_name == "MULTISAMPLE_4X_FOSGAMMA")
         return AA_MODE_METHOD_MULTISAMPLE_4X_FOSGAMMA;
      else if (value_name == "MULTISAMPLE_2X_DIAGONAL_FOSGAMMA")
         return AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA;
      else if (value_name == "SUPERSAMPLE_4X_FOSGAMMA")
         return AA_MODE_METHOD_SUPERSAMPLE_4X_FOSGAMMA;
      else if (value_name == "MULTISAMPLE_8X")
         return AA_MODE_METHOD_MULTISAMPLE_8X;
      else if (value_name == "VCAA_8X_4v4")
         return AA_MODE_METHOD_VCAA_8X_4v4;
      else if (value_name == "VCAA_16X_4v12")
         return AA_MODE_METHOD_VCAA_16X_4v12;
      else if (value_name == "VCAA_16X_8v8")
         return AA_MODE_METHOD_VCAA_16X_8v8;
      else if (value_name == "MIXEDSAMPLE_32X")
         return AA_MODE_METHOD_MIXEDSAMPLE_32X;
      else if (value_name == "SUPERVCAA_64X_4v12")
         return AA_MODE_METHOD_SUPERVCAA_64X_4v12;
      else if (value_name == "SUPERVCAA_64X_8v8")
         return AA_MODE_METHOD_SUPERVCAA_64X_8v8;
      else if (value_name == "MIXEDSAMPLE_64X")
         return AA_MODE_METHOD_MIXEDSAMPLE_64X;
      else if (value_name == "MIXEDSAMPLE_128X")
         return AA_MODE_METHOD_MIXEDSAMPLE_128X;
      else if (value_name == "COUNT")
         return AA_MODE_METHOD_COUNT;
      else if (value_name == "METHOD_MASK")
         return AA_MODE_METHOD_METHOD_MASK;
      else if (value_name == "METHOD_MAX")
         return AA_MODE_METHOD_METHOD_MAX;
   }
   else if (setting_name == "Antialiasing - Transparency Supersampling")
   {
      if (value_name == "SAMPLES_MASK")
         return AA_MODE_REPLAY_SAMPLES_MASK;
      else if (value_name == "SAMPLES_ONE")
         return AA_MODE_REPLAY_SAMPLES_ONE;
      else if (value_name == "SAMPLES_TWO")
         return AA_MODE_REPLAY_SAMPLES_TWO;
      else if (value_name == "SAMPLES_FOUR")
         return AA_MODE_REPLAY_SAMPLES_FOUR;
      else if (value_name == "SAMPLES_EIGHT")
         return AA_MODE_REPLAY_SAMPLES_EIGHT;
      else if (value_name == "SAMPLES_MAX")
         return AA_MODE_REPLAY_SAMPLES_MAX;
      else if (value_name == "MODE_MASK")
         return AA_MODE_REPLAY_MODE_MASK;
      else if (value_name == "MODE_OFF")
         return AA_MODE_REPLAY_MODE_OFF;
      else if (value_name == "MODE_ALPHA_TEST")
         return AA_MODE_REPLAY_MODE_ALPHA_TEST;
      else if (value_name == "MODE_PIXEL_KILL")
         return AA_MODE_REPLAY_MODE_PIXEL_KILL;
      else if (value_name == "MODE_DYN_BRANCH")
         return AA_MODE_REPLAY_MODE_DYN_BRANCH;
      else if (value_name == "MODE_OPTIMAL")
         return AA_MODE_REPLAY_MODE_OPTIMAL;
      else if (value_name == "MODE_ALL")
         return AA_MODE_REPLAY_MODE_ALL;
      else if (value_name == "MODE_MAX")
         return AA_MODE_REPLAY_MODE_MAX;
      else if (value_name == "TRANSPARENCY")
         return AA_MODE_REPLAY_TRANSPARENCY;
      else if (value_name == "DISALLOW_TRAA")
         return AA_MODE_REPLAY_DISALLOW_TRAA;
      else if (value_name == "TRANSPARENCY_DEFAULT")
         return AA_MODE_REPLAY_TRANSPARENCY_DEFAULT;
      else if (value_name == "TRANSPARENCY_DEFAULT_TESLA")
         return AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA;
      else if (value_name == "TRANSPARENCY_DEFAULT_FERMI")
         return AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI;
   }
   else if (setting_name == "Antialiasing - Mode")
   {
      if (value_name == "MASK")
         return AA_MODE_SELECTOR_MASK;
      else if (value_name == "APP_CONTROL")
         return AA_MODE_SELECTOR_APP_CONTROL;
      else if (value_name == "OVERRIDE")
         return AA_MODE_SELECTOR_OVERRIDE;
      else if (value_name == "ENHANCE")
         return AA_MODE_SELECTOR_ENHANCE;
      else if (value_name == "MAX")
         return AA_MODE_SELECTOR_MAX;
   }
   else if (setting_name == "Antialiasing - SLI AA")
   {
      if (value_name == "DISABLED")
         return AA_MODE_SELECTOR_SLIAA_DISABLED;
      else if (value_name == "ENABLED")
         return AA_MODE_SELECTOR_SLIAA_ENABLED;
   }
   else if (setting_name == "Anisotropic filtering setting")
   {
      if (value_name == "MASK")
         return ANISO_MODE_LEVEL_MASK;
      else if (value_name == "NONE_POINT")
         return ANISO_MODE_LEVEL_NONE_POINT;
      else if (value_name == "NONE_LINEAR")
         return ANISO_MODE_LEVEL_NONE_LINEAR;
      else if (value_name == "MAX")
         return ANISO_MODE_LEVEL_MAX;
   }
   else if (setting_name == "Anisotropic filtering mode")
   {
      if (value_name == "MASK")
         return ANISO_MODE_SELECTOR_MASK;
      else if (value_name == "APP")
         return ANISO_MODE_SELECTOR_APP;
      else if (value_name == "USER")
         return ANISO_MODE_SELECTOR_USER;
      else if (value_name == "COND")
         return ANISO_MODE_SELECTOR_COND;
      else if (value_name == "MAX")
         return ANISO_MODE_SELECTOR_MAX;
   }
   else if (setting_name == "Application Profile Notification Popup Timeout")
   {
      if (value_name == "DISABLED")
         return APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_DISABLED;
      else if (value_name == "NINE_SECONDS")
         return APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_NINE_SECONDS;
      else if (value_name == "FIFTEEN_SECONDS")
         return APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_FIFTEEN_SECONDS;
      else if (value_name == "THIRTY_SECONDS")
         return APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_THIRTY_SECONDS;
      else if (value_name == "ONE_MINUTE")
         return APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ONE_MINUTE;
      else if (value_name == "TWO_MINUTE")
         return APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_TWO_MINUTES;
   }
   else if (setting_name == "Do not display this profile in the Control Panel")
   {
      if (value_name == "DISABLED")
         return CPL_HIDDEN_PROFILE_DISABLED;
      else if (value_name == "ENABLED")
         return CPL_HIDDEN_PROFILE_ENABLED;
   }
   else if (setting_name == "Export Performance Counters")
   {
      if (value_name == "OFF")
         return EXPORT_PERF_COUNTERS_OFF;
      else if (value_name == "ON")
         return EXPORT_PERF_COUNTERS_ON;
   }
   else if (setting_name == "NVIDIA Predefined FXAA Usage")
   {
      if (value_name == "DISALLOWED")
         return FXAA_ALLOW_DISALLOWED;
      else if (value_name == "ALLOWED")
         return FXAA_ALLOW_ALLOWED;
   }
   else if (setting_name == "Toggle FXAA on or off")
   {
      if (value_name == "OFF")
         return FXAA_ENABLE_OFF;
      else if (value_name == "ON")
         return FXAA_ENABLE_ON;
   }
   else if (setting_name == "Toggle FXAA Indicator on or off")
   {
      if (value_name == "OFF")
         return FXAA_INDICATOR_ENABLE_OFF;
      else if (value_name == "ON")
         return FXAA_INDICATOR_ENABLE_ON;
   }
   else if (setting_name == "Show the SLI on-screen indicator")
   {
      if (value_name == "DISABLED")
         return MCSFRSHOWSPLIT_DISABLED;
      else if (value_name == "ENABLED")
         return MCSFRSHOWSPLIT_ENABLED;
   }
   else if (setting_name == "Debug bits for optimus")
   {
      if (value_name == "RENDER_TRANSPORT")
         return OPTIMUS_DEBUG_NULL_RENDER_TRANSPORT;
      else if (value_name == "DISPLAY_TRANSPORT")
         return OPTIMUS_DEBUG_NULL_DISPLAY_TRANSPORT;
   }
   else if (setting_name == "Maximum AA samples allowed for a given application")
   {
      if (value_name == "MIN")
         return OPTIMUS_MAXAA_MIN;
      else if (value_name == "MAX")
         return OPTIMUS_MAXAA_MAX;
   }
   else if (setting_name == "Display the PhysX indicator")
   {
      if (value_name == "DISABLED")
         return PHYSXINDICATOR_DISABLED;
      else if (value_name == "ENABLED")
         return PHYSXINDICATOR_ENABLED;
   }
   else if (setting_name == "Power management mode")
   {
      if (value_name == "ADAPTIVE")
         return PREFERRED_PSTATE_ADAPTIVE;
      else if (value_name == "PREFER_MAX")
         return PREFERRED_PSTATE_PREFER_MAX;
      else if (value_name == "CONTROLLED")
         return PREFERRED_PSTATE_DRIVER_CONTROLLED;
      else if (value_name == "PREFER_MIN")
         return PREFERRED_PSTATE_PREFER_MIN;
      else if (value_name == "MIN")
         return PREFERRED_PSTATE_MIN;
      else if (value_name == "MAX")
         return PREFERRED_PSTATE_MAX;
   }
   else if (setting_name == "Frame Rate Limiter")
   {
      if (value_name == "DISABLED")
         return PS_FRAMERATE_LIMITER_DISABLED;
      else if (value_name == "FPS_20")
         return PS_FRAMERATE_LIMITER_FPS_20;
      else if (value_name == "FPS_30")
         return PS_FRAMERATE_LIMITER_FPS_30;
      else if (value_name == "FPS_40")
         return PS_FRAMERATE_LIMITER_FPS_40;
      else if (value_name == "FPSMASK")
         return PS_FRAMERATE_LIMITER_FPSMASK;
      else if (value_name == "GPS_WEB")
         return PS_FRAMERATE_LIMITER_GPS_WEB;
      else if (value_name == "FORCE_OPTIMUS_POLICY")
         return PS_FRAMERATE_LIMITER_FORCE_OPTIMUS_POLICY;
      else if (value_name == "DISALLOWED")
         return PS_FRAMERATE_LIMITER_DISALLOWED;
      else if (value_name == "THRESHOLD")
         return PS_FRAMERATE_LIMITER_THRESHOLD;
      else if (value_name == "TEMPERATURE")
         return PS_FRAMERATE_LIMITER_TEMPERATURE;
      else if (value_name == "POWER")
         return PS_FRAMERATE_LIMITER_POWER;
      else if (value_name == "MODEMASK")
         return PS_FRAMERATE_LIMITER_MODEMASK;
      else if (value_name == "ACCURATE")
         return PS_FRAMERATE_LIMITER_ACCURATE;
      else if (value_name == "ALLOW_WINDOWED")
         return PS_FRAMERATE_LIMITER_ALLOW_WINDOWED;
      else if (value_name == "FORCEON")
         return PS_FRAMERATE_LIMITER_FORCEON;
      else if (value_name == "ENABLED")
         return PS_FRAMERATE_LIMITER_ENABLED;
      else if (value_name == "MASK")
         return PS_FRAMERATE_LIMITER_MASK;
   }
   else if (setting_name == "iGPU transcoding")
   {
      if (value_name == "DISABLE")
         return SHIM_IGPU_TRANSCODING_DISABLE;
      else if (value_name == "ENABLE")
         return SHIM_IGPU_TRANSCODING_ENABLE;
   }
   else if (setting_name == "Optimus flags for enabled applications")
   {
      if (value_name == "INTEGRATED")
         return SHIM_MCCOMPAT_INTEGRATED;
      else if (value_name == "ENABLE")
         return SHIM_MCCOMPAT_ENABLE;
      else if (value_name == "USER_EDITABLE")
         return SHIM_MCCOMPAT_USER_EDITABLE;
      else if (value_name == "MASK")
         return SHIM_MCCOMPAT_MASK;
      else if (value_name == "VIDEO_MASK")
         return SHIM_MCCOMPAT_VIDEO_MASK;
      else if (value_name == "VARYING_BIT")
         return SHIM_MCCOMPAT_VARYING_BIT;
      else if (value_name == "AUTO_SELECT")
         return SHIM_MCCOMPAT_AUTO_SELECT;
      else if (value_name == "OVERRIDE_BIT")
         return SHIM_MCCOMPAT_OVERRIDE_BIT;
   }
   else if (setting_name == "Enable application for Optimus")
   {
      if (value_name == "INTEGRATED")
         return SHIM_RENDERING_MODE_INTEGRATED;
      else if (value_name == "ENABLE")
         return SHIM_RENDERING_MODE_ENABLE;
      else if (value_name == "USER_EDITABLE")
         return SHIM_RENDERING_MODE_USER_EDITABLE;
      else if (value_name == "MASK")
         return SHIM_RENDERING_MODE_MASK;
      else if (value_name == "VIDEO_MASK")
         return SHIM_RENDERING_MODE_VIDEO_MASK;
      else if (value_name == "VARYING_BIT")
         return SHIM_RENDERING_MODE_VARYING_BIT;
      else if (value_name == "AUTO_SELECT")
         return SHIM_RENDERING_MODE_AUTO_SELECT;
      else if (value_name == "OVERRIDE_BIT")
         return SHIM_RENDERING_MODE_OVERRIDE_BIT;
   }
   else if (setting_name == "Shim Rendering Mode Options per application for Optimus")
   {
      if (value_name == "DEFAULT_RENDERING_MODE")
         return SHIM_RENDERING_OPTIONS_DEFAULT_RENDERING_MODE;
      else if (value_name == "DISABLE_ASYNC_PRESENT")
         return SHIM_RENDERING_OPTIONS_DISABLE_ASYNC_PRESENT;
      else if (value_name == "EHSHELL_DETECT")
         return SHIM_RENDERING_OPTIONS_EHSHELL_DETECT;
      else if (value_name == "FLASHPLAYER_HOST_DETECT")
         return SHIM_RENDERING_OPTIONS_FLASHPLAYER_HOST_DETECT;
      else if (value_name == "VIDEO_DRM_APP_DETECT")
         return SHIM_RENDERING_OPTIONS_VIDEO_DRM_APP_DETECT;
      else if (value_name == "IGNORE_OVERRIDES")
         return SHIM_RENDERING_OPTIONS_IGNORE_OVERRIDES;
      else if (value_name == "CHILDPROCESS_DETECT")
         return SHIM_RENDERING_OPTIONS_CHILDPROCESS_DETECT;
      else if (value_name == "ENABLE_DWM_ASYNC_PRESENT")
         return SHIM_RENDERING_OPTIONS_ENABLE_DWM_ASYNC_PRESENT;
      else if (value_name == "PARENTPROCESS_DETECT")
         return SHIM_RENDERING_OPTIONS_PARENTPROCESS_DETECT;
      else if (value_name == "ALLOW_INHERITANCE")
         return SHIM_RENDERING_OPTIONS_ALLOW_INHERITANCE;
      else if (value_name == "DISABLE_WRAPPERS")
         return SHIM_RENDERING_OPTIONS_DISABLE_WRAPPERS;
      else if (value_name == "DISABLE_DXGI_WRAPPERS")
         return SHIM_RENDERING_OPTIONS_DISABLE_DXGI_WRAPPERS;
      else if (value_name == "PRUNE_UNSUPPORTED_FORMATS")
         return SHIM_RENDERING_OPTIONS_PRUNE_UNSUPPORTED_FORMATS;
      else if (value_name == "ENABLE_ALPHA_FORMAT")
         return SHIM_RENDERING_OPTIONS_ENABLE_ALPHA_FORMAT;
      else if (value_name == "IGPU_TRANSCODING")
         return SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING;
      else if (value_name == "DISABLE_CUDA")
         return SHIM_RENDERING_OPTIONS_DISABLE_CUDA;
      else if (value_name == "ALLOW_CP_CAPS_FOR_VIDEO")
         return SHIM_RENDERING_OPTIONS_ALLOW_CP_CAPS_FOR_VIDEO;
      else if (value_name == "ENABLE_NEW_HOOKING")
         return SHIM_RENDERING_OPTIONS_ENABLE_NEW_HOOKING;
      else if (value_name == "DISABLE_DURING_SECURE_BOOT")
         return SHIM_RENDERING_OPTIONS_DISABLE_DURING_SECURE_BOOT;
   }
   else if (setting_name == "Number of GPUs to use on SLI rendering mode")
   {
      if (value_name == "AUTOSELECT")
         return SLI_GPU_COUNT_AUTOSELECT;
      else if (value_name == "ONE")
         return SLI_GPU_COUNT_ONE;
      else if (value_name == "TWO")
         return SLI_GPU_COUNT_TWO;
      else if (value_name == "THREE")
         return SLI_GPU_COUNT_THREE;
      else if (value_name == "FOUR")
         return SLI_GPU_COUNT_FOUR;
   }
   else if (setting_name == "NVIDIA predefined number of GPUs to use on SLI rendering mode")
   {
      if (value_name == "AUTOSELECT")
         return SLI_PREDEFINED_GPU_COUNT_AUTOSELECT;
      else if (value_name == "ONE")
         return SLI_PREDEFINED_GPU_COUNT_ONE;
      else if (value_name == "TWO")
         return SLI_PREDEFINED_GPU_COUNT_TWO;
      else if (value_name == "THREE")
         return SLI_PREDEFINED_GPU_COUNT_THREE;
      else if (value_name == "FOUR")
         return SLI_PREDEFINED_GPU_COUNT_FOUR;
   }
   else if (setting_name == "NVIDIA predefined number of GPUs to use on SLI rendering mode on DirectX 10")
   {
      if (value_name == "AUTOSELECT")
         return SLI_PREDEFINED_GPU_COUNT_DX10_AUTOSELECT;
      else if (value_name == "ONE")
         return SLI_PREDEFINED_GPU_COUNT_DX10_ONE;
      else if (value_name == "TWO")
         return SLI_PREDEFINED_GPU_COUNT_DX10_TWO;
      else if (value_name == "THREE")
         return SLI_PREDEFINED_GPU_COUNT_DX10_THREE;
      else if (value_name == "FOUR")
         return SLI_PREDEFINED_GPU_COUNT_DX10_FOUR;
   }
   else if (setting_name == "NVIDIA predefined SLI mode")
   {
      if (value_name == "AUTOSELECT")
         return SLI_PREDEFINED_MODE_AUTOSELECT;
      else if (value_name == "FORCE_SINGLE")
         return SLI_PREDEFINED_MODE_FORCE_SINGLE;
      else if (value_name == "FORCE_AFR")
         return SLI_PREDEFINED_MODE_FORCE_AFR;
      else if (value_name == "FORCE_AFR2")
         return SLI_PREDEFINED_MODE_FORCE_AFR2;
      else if (value_name == "FORCE_SFR")
         return SLI_PREDEFINED_MODE_FORCE_SFR;
      else if (value_name == "FORCE_AFR_OF_SFR__FALLBACK_3AFR")
         return SLI_PREDEFINED_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR;
   }
   else if (setting_name == "NVIDIA predefined SLI mode on DirectX 10")
   {
      if (value_name == "AUTOSELECT")
         return SLI_PREDEFINED_MODE_DX10_AUTOSELECT;
      else if (value_name == "FORCE_SINGLE")
         return SLI_PREDEFINED_MODE_DX10_FORCE_SINGLE;
      else if (value_name == "FORCE_AFR")
         return SLI_PREDEFINED_MODE_DX10_FORCE_AFR;
      else if (value_name == "FORCE_AFR2")
         return SLI_PREDEFINED_MODE_DX10_FORCE_AFR2;
      else if (value_name == "FORCE_SFR")
         return SLI_PREDEFINED_MODE_DX10_FORCE_SFR;
      else if (value_name == "FORCE_AFR_OF_SFR__FALLBACK_3AFR")
         return SLI_PREDEFINED_MODE_DX10_FORCE_AFR_OF_SFR__FALLBACK_3AFR;
   }
   else if (setting_name == "SLI rendering mode")
   {
      if (value_name == "AUTOSELECT")
         return SLI_RENDERING_MODE_AUTOSELECT;
      else if (value_name == "FORCE_SINGLE")
         return SLI_RENDERING_MODE_FORCE_SINGLE;
      else if (value_name == "FORCE_AFR")
         return SLI_RENDERING_MODE_FORCE_AFR;
      else if (value_name == "FORCE_AFR2")
         return SLI_RENDERING_MODE_FORCE_AFR2;
      else if (value_name == "FORCE_SFR")
         return SLI_RENDERING_MODE_FORCE_SFR;
      else if (value_name == "FORCE_AFR_OF_SFR__FALLBACK_3AFR")
         return SLI_RENDERING_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR;
   }
   else if (setting_name == "Flag to control smooth AFR behavior")
   {
      if (value_name == "OFF")
         return VSYNCSMOOTHAFR_OFF;
      else if (value_name == "ON")
         return VSYNCSMOOTHAFR_ON;
   }
   else if (setting_name == "Vsync - Behavior Flags")
   {
      if (value_name == "NONE")
         return VSYNC_BEHAVIOR_FLAGS_NONE;
      else if (value_name == "DEFAULT")
         return VSYNC_BEHAVIOR_FLAGS_DEFAULT;
      else if (value_name == "IGNORE_FLIPINTERVAL_MULTIPLE")
         return VSYNC_BEHAVIOR_FLAGS_IGNORE_FLIPINTERVAL_MULTIPLE;
   }
   else if (setting_name == "Stereo - Swap eyes")
   {
      if (value_name == "OFF")
         return WKS_API_STEREO_EYES_EXCHANGE_OFF;
      else if (value_name == "ON")
         return WKS_API_STEREO_EYES_EXCHANGE_ON;
   }
   else if (setting_name == "Stereo - Display mode")
   {
      if (value_name == "SHUTTER_GLASSES")
         return WKS_API_STEREO_MODE_SHUTTER_GLASSES;
      else if (value_name == "VERTICAL_INTERLACED")
         return WKS_API_STEREO_MODE_VERTICAL_INTERLACED;
      else if (value_name == "TWINVIEW")
         return WKS_API_STEREO_MODE_TWINVIEW;
      else if (value_name == "NV17_SHUTTER_GLASSES_AUTO")
         return WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO;
      else if (value_name == "NV17_SHUTTER_GLASSES_DAC0")
         return WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0;
      else if (value_name == "NV17_SHUTTER_GLASSES_DAC1")
         return WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1;
      else if (value_name == "COLOR_LINE")
         return WKS_API_STEREO_MODE_COLOR_LINE;
      else if (value_name == "COLOR_INTERLEAVED")
         return WKS_API_STEREO_MODE_COLOR_INTERLEAVED;
      else if (value_name == "ANAGLYPH")
         return WKS_API_STEREO_MODE_ANAGLYPH;
      else if (value_name == "HORIZONTAL_INTERLACED")
         return WKS_API_STEREO_MODE_HORIZONTAL_INTERLACED;
      else if (value_name == "SIDE_FIELD")
         return WKS_API_STEREO_MODE_SIDE_FIELD;
      else if (value_name == "SUB_FIELD")
         return WKS_API_STEREO_MODE_SUB_FIELD;
      else if (value_name == "CHECKERBOARD")
         return WKS_API_STEREO_MODE_CHECKERBOARD;
      else if (value_name == "INVERSE_CHECKERBOARD")
         return WKS_API_STEREO_MODE_INVERSE_CHECKERBOARD;
      else if (value_name == "TRIDELITY_SL")
         return WKS_API_STEREO_MODE_TRIDELITY_SL;
      else if (value_name == "TRIDELITY_MV")
         return WKS_API_STEREO_MODE_TRIDELITY_MV;
      else if (value_name == "SEEFRONT")
         return WKS_API_STEREO_MODE_SEEFRONT;
      else if (value_name == "STEREO_MIRROR")
         return WKS_API_STEREO_MODE_STEREO_MIRROR;
      else if (value_name == "FRAME_SEQUENTIAL")
         return WKS_API_STEREO_MODE_FRAME_SEQUENTIAL;
      else if (value_name == "AUTODETECT_PASSIVE_MODE")
         return WKS_API_STEREO_MODE_AUTODETECT_PASSIVE_MODE;
      else if (value_name == "AEGIS_DT_FRAME_SEQUENTIAL")
         return WKS_API_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL;
      else if (value_name == "OEM_EMITTER_FRAME_SEQUENTIAL")
         return WKS_API_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL;
      else if (value_name == "USE_HW_DEFAULT")
         return WKS_API_STEREO_MODE_USE_HW_DEFAULT;
      else if (value_name == "DEFAULT_GL")
         return WKS_API_STEREO_MODE_DEFAULT_GL;
   }
   else if (setting_name == "Stereo - Win8 support")
   {
      if (value_name == "OFF")
         return WKS_FEATURE_SUPPORT_CONTROL_OFF;
      else if (value_name == "SRS_1714_WIN8_STEREO")
         return WKS_FEATURE_SUPPORT_CONTROL_SRS_1714_WIN8_STEREO;
      else if (value_name == "WIN8_STEREO_EXPORT_IF_ENABLED")
         return WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_EXPORT_IF_ENABLED;
   }
   else if (setting_name == "Stereo - Dongle Support")
   {
      if (value_name == "OFF")
         return WKS_STEREO_DONGLE_SUPPORT_OFF;
      else if (value_name == "DAC")
         return WKS_STEREO_DONGLE_SUPPORT_DAC;
      else if (value_name == "DLP")
         return WKS_STEREO_DONGLE_SUPPORT_DLP;
   }
   else if (setting_name == "Stereo - Enable")
   {
      if (value_name == "OFF")
         return WKS_STEREO_SUPPORT_OFF;
      else if (value_name == "ON")
         return WKS_STEREO_SUPPORT_ON;
   }
   else if (setting_name == "Ambient Occlusion")
   {
      if (value_name == "OFF")
         return AO_MODE_OFF;
      else if (value_name == "LOW")
         return AO_MODE_LOW;
      else if (value_name == "MEDIUM")
         return AO_MODE_MEDIUM;
      else if (value_name == "HIGH")
         return AO_MODE_HIGH;
   }
   else if (setting_name == "NVIDIA Predefined Ambient Occlusion Usage")
   {
      if (value_name == "DISABLED")
         return AO_MODE_ACTIVE_DISABLED;
      else if (value_name == "ENABLED")
         return AO_MODE_ACTIVE_ENABLED;
   }
   else if (setting_name == "Texture filtering - Driver Controlled LOD Bias")
   {
      if (value_name == "OFF")
         return AUTO_LODBIASADJUST_OFF;
      else if (value_name == "ON")
         return AUTO_LODBIASADJUST_ON;
   }
   else if (setting_name == "Texture filtering - LOD Bias")
   {
      if (value_name == "MIN")
         return LODBIASADJUST_MIN;
      else if (value_name == "MAX")
         return LODBIASADJUST_MAX;
   }
   else if (setting_name == "Maximum pre-rendered frames")
   {
      if (value_name == "MIN")
         return PRERENDERLIMIT_MIN;
      else if (value_name == "MAX")
         return PRERENDERLIMIT_MAX;
      else if (value_name == "APP_CONTROLLED")
         return PRERENDERLIMIT_APP_CONTROLLED;
   }
   else if (setting_name == "Dynamic tiling")
   {
      if (value_name == "OFF")
         return PS_DYNAMIC_TILING_OFF;
      else if (value_name == "ON")
         return PS_DYNAMIC_TILING_ON;
   }
   else if (setting_name == "Texture filtering - Anisotropic sample optimization")
   {
      if (value_name == "OFF")
         return PS_TEXFILTER_ANISO_OPTS2_OFF;
      else if (value_name == "ON")
         return PS_TEXFILTER_ANISO_OPTS2_ON;
   }
   else if (setting_name == "Texture filtering - Anisotropic filter optimization")
   {
      if (value_name == "OFF")
         return PS_TEXFILTER_BILINEAR_IN_ANISO_OFF;
      else if (value_name == "ON")
         return PS_TEXFILTER_BILINEAR_IN_ANISO_ON;
   }
   else if (setting_name == "Texture filtering - Trilinear optimization")
   {
      if (value_name == "OFF")
         return PS_TEXFILTER_DISABLE_TRILIN_SLOPE_OFF;
      else if (value_name == "ON")
         return PS_TEXFILTER_DISABLE_TRILIN_SLOPE_ON;
   }
   else if (setting_name == "Texture filtering - Negative LOD bias")
   {
      if (value_name == "OFF")
         return PS_TEXFILTER_NO_NEG_LODBIAS_OFF;
      else if (value_name == "ON")
         return PS_TEXFILTER_NO_NEG_LODBIAS_ON;
   }
   else if (setting_name == "Texture filtering - Quality")
   {
      if (value_name == "HIGHQUALITY")
         return QUALITY_ENHANCEMENTS_HIGHQUALITY;
      else if (value_name == "QUALITY")
         return QUALITY_ENHANCEMENTS_QUALITY;
      else if (value_name == "PERFORMANCE")
         return QUALITY_ENHANCEMENTS_PERFORMANCE;
      else if (value_name == "HIGHPERFORMANCE")
         return QUALITY_ENHANCEMENTS_HIGHPERFORMANCE;
   }
   else if (setting_name == "Preferred refresh rate")
   {
      if (value_name == "APPLICATION_CONTROLLED")
         return REFRESH_RATE_OVERRIDE_APPLICATION_CONTROLLED;
      else if (value_name == "HIGHEST_AVAILABLE")
         return REFRESH_RATE_OVERRIDE_HIGHEST_AVAILABLE;
   }
   else if (setting_name == "PowerThrottle")
   {
      if (value_name == "OFF")
         return SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_OFF;
      else if (value_name == "ON")
         return SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_ON;
   }
   else if (setting_name == "VAB Default Data")
   {
      if (value_name == "ZERO")
         return SET_VAB_DATA_ZERO;
      else if (value_name == "UINT_ONE")
         return SET_VAB_DATA_UINT_ONE;
      else if (value_name == "FLOAT_ONE")
         return SET_VAB_DATA_FLOAT_ONE;
      else if (value_name == "FLOAT_POS_INF")
         return SET_VAB_DATA_FLOAT_POS_INF;
      else if (value_name == "FLOAT_NAN")
         return SET_VAB_DATA_FLOAT_NAN;
      else if (value_name == "USE_API_DEFAULTS")
         return SET_VAB_DATA_USE_API_DEFAULTS;
   }
   else if (setting_name == "Vertical Sync")
   {
      if (value_name == "PASSIVE")
         return VSYNCMODE_PASSIVE;
      else if (value_name == "FORCEOFF")
         return VSYNCMODE_FORCEOFF;
      else if (value_name == "FORCEON")
         return VSYNCMODE_FORCEON;
      else if (value_name == "FLIPINTERVAL2")
         return VSYNCMODE_FLIPINTERVAL2;
      else if (value_name == "FLIPINTERVAL3")
         return VSYNCMODE_FLIPINTERVAL3;
      else if (value_name == "FLIPINTERVAL4")
         return VSYNCMODE_FLIPINTERVAL4;
   }
   else if (setting_name == "Vertical Sync Tear Control")
   {
      if (value_name == "DISABLE")
         return VSYNCTEARCONTROL_DISABLE;
      else if (value_name == "ENABLE")
         return VSYNCTEARCONTROL_ENABLE;
   }

   return 0;
}