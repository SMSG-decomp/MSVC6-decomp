int __fastcall hash_scope_has_entries(c1xx_hash_scope *scope)

{
  if ((scope->buckets == (c1_sym_link **)0x0) && (scope->using_list == (c1_using_cell **)0x0)) {
    return 0;
  }
  return 1;
}

