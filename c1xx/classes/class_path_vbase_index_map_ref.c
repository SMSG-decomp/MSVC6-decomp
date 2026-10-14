c1_node * __cdecl class_path_vbase_index_map_ref(c1_keyed_cell *path,int reverse)

{
  c1_keyed_cell *pcVar1;
  c1_keyed_cell *pcVar2;
  c1_vbase_map_key *pcVar3;
  c1_symbol *pcVar4;
  c1_node *pcVar5;
  c1_symbol *value;
  
  pcVar1 = class_path_first_reindexing_step(path);
  if (pcVar1 == (c1_keyed_cell *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar2 = class_path_outermost_reindexing_parent(path);
  pcVar4 = pcVar2->sym;
  if ((pcVar4->kind & 0x1f) == 0xf) {
    pcVar4 = g_scope_vector->entries[(short)pcVar4->key_ref];
  }
  pcVar3 = class_vbase_map_key_new
                     (g_scope_vector->entries[(short)pcVar1->sym->key_ref],pcVar4,(c1_u8)reverse,5);
  if (g_pointer_pair_table == (c1_symtab *)0x0) {
    g_pointer_pair_table = symtab_new(0x20,0,0xf,0xe,'\x01','\x01');
  }
  pcVar4 = symtab_lookup(g_pointer_pair_table,pcVar3);
  if (pcVar4 == (c1_symbol *)0x0) {
    pcVar4 = class_vbase_map_declare_vdispmap(pcVar3);
    value = pcVar4;
    pcVar3 = class_vbase_map_key_copy(pcVar3,0);
    symtab_insert(g_pointer_pair_table,pcVar3,value);
  }
  pcVar5 = tree_new_symbol_ref(pcVar4,'\0');
  return pcVar5;
}

