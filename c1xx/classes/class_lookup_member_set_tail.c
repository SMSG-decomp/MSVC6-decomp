c1_symbol * __thiscall
class_lookup_member_set_tail
          (c1_keyed_list *paths,c1_symbol *cls,void *name,char ambiguous,c1_keyed_list *result,
          uint flags,int err)

{
  c1_keyed_cell *pcVar1;
  c1_keyed_cell *pcVar2;
  c1_keyed_cell *pcVar3;
  c1_arena *a;
  c1_u8 *pcVar4;
  uint uVar5;
  c1_symbol *pcVar6;
  
  if (((((flags & 1) == 0) || (cls->name != name)) && (pcVar1 = paths->head, pcVar1 != paths->tail))
     && ((flags & 0x80) == 0)) {
    if (err != 0) {
      ambiguous = '\x01';
      pcVar2 = pcVar1;
      for (pcVar3 = pcVar1->key; pcVar3 != (c1_keyed_cell *)0x0; pcVar3 = pcVar3->key) {
        pcVar2 = pcVar3;
      }
      diag_error((short)err,pcVar2->sym,name);
      for (pcVar2 = pcVar1; paths = result, pcVar2 != (c1_keyed_cell *)0x0; pcVar2 = pcVar2->next) {
        pcVar4 = base_path_text_for_diag((int *)pcVar2,1);
        diag_warning(1,err,(pcVar2 != pcVar1) + 0x17c,name,pcVar4);
      }
    }
    paths->tail = paths->head;
    paths->head->next = (c1_keyed_cell *)0x0;
  }
  if ((g_compile_flags_c4 & 0x400) == 0) {
    if ((((g_block_depth != '\0') && (g_class_depth < 0)) &&
        ((g_compile_flags_c8 & 0x10000000) == 0)) &&
       (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
         ((g_compile_flags_c4 & 0x200) != 0)) && (((byte)g_compile_flags_cc & 0x50) == 0)))) {
      flags = 4;
      goto LAB_1040db8e;
    }
    flags = 0;
  }
  else {
    flags = g_token_arena_index;
    if (g_token_arena_index != 0) goto LAB_1040db8e;
  }
  if ((void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]] != (void **)0x0) {
    pcVar6 = sym_record_reuse_tail
                       (g_symbol_size_class_table[0x12],
                        (void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]],name,ambiguous
                        ,(int *)result,flags);
    return pcVar6;
  }
LAB_1040db8e:
  a = g_arenas + flags;
  uVar5 = g_symbol_size_table[0x12] + 3;
  pcVar6 = (c1_symbol *)a->cur;
  pcVar4 = g_arenas[flags].end;
  a->cur = &pcVar6->kind + (uVar5 & 0xfffffffc);
  if (pcVar4 < &pcVar6->kind + (uVar5 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pcVar6 == (c1_symbol *)0x0) {
    pcVar6 = (c1_symbol *)0x0;
  }
  else {
    pcVar6->kind = pcVar6->kind & 0xf2 | 0x12;
    if (&pcVar6->name != (fe_name **)0x0) {
      pcVar6->name = name;
      pcVar6->next = (c1_symbol *)0x0;
    }
  }
  pcVar6->type = (c1_type *)result;
  if (ambiguous != '\0') {
    pcVar6->flags3 = pcVar6->flags3 | 4;
  }
  return pcVar6;
}

