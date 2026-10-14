int __cdecl pragma_implementation_key(void)

{
  char cVar1;
  uint key;
  uint uVar2;
  void *pvVar3;
  
  pvVar3 = g_token_newline;
  key = pragma_check_integral_constant();
  uVar2 = pp_input_file_flag8();
  cVar1 = (char)uVar2;
  while (((cVar1 != '\0' && (key != 0)) &&
         (pvVar3 = import_map_take_implementation_key
                             ((c1_import_key_list *)(g_import_implementation_keys + 4),key,'\0'),
         pvVar3 == (void *)0x0))) {
    pp_check_expected_endif(8);
    key = pragma_check_integral_constant();
    uVar2 = pp_input_file_flag8();
    cVar1 = (char)uVar2;
  }
  return (int)pvVar3;
}

