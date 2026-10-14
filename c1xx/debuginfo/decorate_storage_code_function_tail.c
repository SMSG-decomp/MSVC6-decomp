byte * __cdecl decorate_storage_code_function_tail(byte *out,c1_symbol *sym)

{
  char *out_00;
  byte *pbVar1;
  
  out_00 = decorate_type_into((char *)out,
                              (c1_type *)
                              **(undefined4 **)
                                (((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8),1);
  pbVar1 = (byte *)decorate_function_symbol_type(out_00,sym);
  return pbVar1;
}

