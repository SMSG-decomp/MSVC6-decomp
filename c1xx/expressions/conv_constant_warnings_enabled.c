char __fastcall conv_constant_warnings_enabled(c1_conversion *conv)

{
  if (1 < g_warning_state->level) {
    switch(conv->op) {
    case '4':
    case ':':
    case 'G':
    case 'K':
    case 'R':
    case '`':
    case 't':
    case '}':
      return '\x01';
    }
  }
  return '\0';
}

