char __cdecl sym_check_owner_scope(char *out,c1_symbol *sym)

{
  if ((byte)(sym->entity >> 0x18) == g_browse_id_module_byte) {
    return '\0';
  }
  *out = '\x19';
  browse_record_fill_definition((c1xx_browse_record *)out,sym);
  return '\x01';
}

