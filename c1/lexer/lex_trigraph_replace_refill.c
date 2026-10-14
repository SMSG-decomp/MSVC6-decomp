int __cdecl lex_trigraph_replace_refill(byte *input,char qmark)

{
  byte *pbVar1;
  
  pbVar1 = g_input_ptr;
code_r0x1062a050:
  g_input_ptr = pbVar1;
  if (g_macro_expansion_depth != 0) goto switchD_1060283d_caseD_1;
  lex_check_end_of_file();
  input = g_input_ptr + 1;
  pbVar1 = input;
  switch(*g_input_ptr) {
  case 0:
    goto code_r0x1062a050;
  default:
    goto switchD_1060283d_caseD_1;
  case 0x21:
    pbVar1 = input;
    *g_input_ptr = 0x7c;
    g_input_ptr = pbVar1;
    break;
  case 0x27:
    pbVar1 = input;
    *g_input_ptr = 0x5e;
    g_input_ptr = pbVar1;
    break;
  case 0x28:
    pbVar1 = input;
    *g_input_ptr = 0x5b;
    g_input_ptr = pbVar1;
    break;
  case 0x29:
    pbVar1 = input;
    *g_input_ptr = 0x5d;
    g_input_ptr = pbVar1;
    break;
  case 0x2d:
    pbVar1 = input;
    *g_input_ptr = 0x7e;
    g_input_ptr = pbVar1;
    break;
  case 0x2f:
    pbVar1 = input;
    *g_input_ptr = 0x5c;
    g_input_ptr = pbVar1;
    break;
  case 0x3c:
    pbVar1 = input;
    *g_input_ptr = 0x7b;
    g_input_ptr = pbVar1;
    break;
  case 0x3d:
    pbVar1 = input;
    *g_input_ptr = 0x23;
    g_input_ptr = pbVar1;
    break;
  case 0x3e:
    pbVar1 = input;
    *g_input_ptr = 0x7d;
    g_input_ptr = pbVar1;
  }
  g_input_ptr = g_input_ptr + -1;
  return 1;
switchD_1060283d_caseD_1:
  g_input_ptr = input + -1;
  input[-2] = qmark;
  pbVar1 = g_input_ptr + -2;
  g_input_ptr = g_input_ptr + -1;
  *pbVar1 = qmark;
  return 0x40;
}

