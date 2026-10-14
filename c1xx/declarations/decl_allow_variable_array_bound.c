void __fastcall decl_allow_variable_array_bound(c1_decl_record *rec)

{
  rec->layer_flags = rec->layer_flags & 0xfd;
  return;
}

