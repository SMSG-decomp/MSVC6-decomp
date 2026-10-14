bool __cdecl expr_builtin_operator_valid_for_class(byte op,char arity,int class_on_left)

{
  if (arity == '\x01') {
    if ((op != 0x31) && (op != 0x76)) {
      return g_token_class[op] == '=';
    }
  }
  else if (arity == '\x02') {
    switch((uint)op) {
    case 0x34:
    case 0x36:
    case 0x37:
    case 0x74:
      break;
    default:
      return g_token_class[op] == 0x94;
    case 0x56:
      return class_on_left == 0;
    }
  }
  return true;
}

