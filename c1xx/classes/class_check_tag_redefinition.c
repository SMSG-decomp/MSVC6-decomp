c1_symbol * __cdecl class_check_tag_redefinition(void *name,uint kind,undefined4 *insert_fn)

{
  void *name_00;
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  c1_lookup_entry *pcVar3;
  char cVar4;
  ushort uVar5;
  
  name_00 = name;
  if (((g_compile_flags_c8 & 0x40000000) == 0) && (((byte)g_compile_flags_c4 & 0x20) != 0)) {
    func_definition_end('\x01');
  }
  if (name != (void *)0x0) {
    if (((g_compile_flags_c8 & 0x40000000) == 0) ||
       (name._0_1_ = '\x01', (code *)*insert_fn != scope_insert_into_enclosing_namespace)) {
      name._0_1_ = '\0';
    }
    pcVar1 = scope_lookup_tag_current_or_namespace(g_current_scope,name_00,(char)name);
    if (pcVar1 != (c1_u8 *)0x0) {
      pcVar2 = *(c1_symbol **)pcVar1;
      *insert_fn = 0;
      if ((pcVar2->kind & 0x1f) == 0x19) {
        diag_error(0x365,pcVar2);
        pcVar2->flags3 = pcVar2->flags3 | 4;
        return pcVar2;
      }
      if (((pcVar2->flags2 & 4) != 0) || ((((pcVar2->detail).cls)->flags3e & 2) != 0)) {
        if ((((pcVar2->detail).cls)->flags3e & 2) == 0) {
          diag_error(0xb,pcVar2,pcVar2->type);
          pcVar2->flags3 = pcVar2->flags3 | 4;
          return pcVar2;
        }
        diag_error(0x3de,pcVar2);
        pcVar2->flags3 = pcVar2->flags3 | 4;
        return pcVar2;
      }
      if (-1 < g_class_depth) {
        pcVar2 = class_check_access_redeclaration
                           (g_class_depth,CONCAT31((int3)((uint)pcVar1 >> 8),pcVar2->flags2),pcVar2)
        ;
        return pcVar2;
      }
      goto LAB_104340d2;
    }
    if ((*(uint *)((int)name_00 + 8) & 0x2000000) != 0) {
      pcVar3 = lookup_name_in_context(g_current_scope,name_00,0x20);
      if (pcVar3 == (c1_lookup_entry *)0x0) {
        pcVar2 = (c1_symbol *)0x0;
      }
      else {
        pcVar2 = pcVar3->sym;
      }
      uVar5 = (ushort)kind & 0x20f;
      if (uVar5 == 0x203) {
        cVar4 = '\x1d';
      }
      else if (uVar5 == 0x201) {
        cVar4 = '\x1a';
      }
      else {
        cVar4 = (uVar5 == 0x202) + '\x1b';
      }
      if (g_block_depth == '\0') {
        diag_error(0x3a6,pcVar2,cVar4,g_class_def_stack[g_class_depth].cls);
        return (c1_symbol *)0x0;
      }
      diag_error(0x3ad,pcVar2,cVar4);
      return (c1_symbol *)0x0;
    }
  }
  pcVar2 = decl_tag_declare(name_00,(ushort)kind,(void **)insert_fn,'\x01');
  if (pcVar2 == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
LAB_104340d2:
  pcVar2 = esu_check_tag_and_begin_enum(pcVar2,kind);
  return pcVar2;
}

