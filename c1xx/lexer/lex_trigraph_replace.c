int __cdecl lex_trigraph_replace(byte *input,char qmark)

{
  byte *pbVar1;
  byte bVar2;
  
  bVar2 = *input;
joined_r0x1040b188:
  g_input_ptr = input + 1;
  if (bVar2 < 0x3f) {
    switch((&switchD_1040b192::switchdataD_1040b1ec)[bVar2]) {
    case 0:
      if (g_macro_expansion_depth == 0) goto code_r0x1045d7ef;
    default:
      goto switchD_1040b192_caseD_1;
    case 0x21:
      g_input_ptr[-1] = 0x7c;
      break;
    case 0x27:
      g_input_ptr[-1] = 0x5e;
      break;
    case 0x28:
      g_input_ptr[-1] = 0x5b;
      break;
    case 0x29:
      g_input_ptr[-1] = 0x5d;
      break;
    case 0x2d:
      g_input_ptr[-1] = 0x7e;
      break;
    case 0x2f:
      g_input_ptr[-1] = 0x5c;
      break;
    case 0x3c:
      g_input_ptr[-1] = 0x7b;
      break;
    case 0x3d:
      g_input_ptr[-1] = 0x23;
      break;
    case 0x3e:
      g_input_ptr[-1] = 0x7d;
    }
    g_input_ptr = g_input_ptr + -1;
    return 1;
  }
switchD_1040b192_caseD_1:
  pbVar1 = g_input_ptr + -2;
  g_input_ptr = g_input_ptr + -1;
  *pbVar1 = qmark;
  pbVar1 = g_input_ptr + -2;
  g_input_ptr = g_input_ptr + -1;
  *pbVar1 = qmark;
  return 0x40;
code_r0x1045d7ef:
  lex_check_end_of_file();
  bVar2 = *g_input_ptr;
  input = g_input_ptr;
  goto joined_r0x1040b188;
}

