char __cdecl ovl_check_c_call_argument_count(c1_type *callee_type,c1_type *fn_type,uint argc)

{
  uint uVar1;
  
  uVar1 = type_function_arity_match(fn_type,argc);
  if (uVar1 == 0) {
    diag_error(0xc5,0x54,callee_type);
    return '\0';
  }
  if (uVar1 != 1) {
    return '\x01';
  }
  diag_error(0xc6,0x54,callee_type);
  return '\0';
}

