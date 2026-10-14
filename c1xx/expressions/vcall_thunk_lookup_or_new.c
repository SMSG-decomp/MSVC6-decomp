void * __cdecl vcall_thunk_lookup_or_new(c1_symbol *member)

{
  c1_vcall_thunk_key *key;
  c1_symbol *pcVar1;
  c1_u8 *key_00;
  c1_symbol *value;
  
  key = vcall_thunk_key_new(member,5);
  if (g_vcall_thunk_table == (c1_symtab *)0x0) {
    g_vcall_thunk_table = symtab_new(0x20,0,6,5,'\x01','\x01');
  }
  pcVar1 = symtab_lookup(g_vcall_thunk_table,key);
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = sym_new_vcall_thunk(key);
    value = pcVar1;
    key_00 = record3_copy((int *)key,0);
    symtab_insert(g_vcall_thunk_table,key_00,value);
  }
  if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
    mre_note_class_use(g_minimal_rebuild_tracker,
                       g_scope_vector->entries[(short)(member->x28).bytes.unk2a]);
  }
  return pcVar1;
}

