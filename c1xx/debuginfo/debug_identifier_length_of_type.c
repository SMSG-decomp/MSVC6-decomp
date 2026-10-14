short __cdecl debug_identifier_length_of_type(byte *out,c1_symbol *sym)

{
  int iVar1;
  char *name;
  
  iVar1 = format_buffer_acquire();
  format_options_set(1);
  format_qualified_name(iVar1,&sym->kind);
  name = format_buffer_text(iVar1);
  iVar1 = debug_identifier_length(out,name);
  format_options_clear(1);
  format_buffer_leave();
  return (short)iVar1;
}

