int * __cdecl class_find_base_paths(void *path,int *state)

{
  int *piVar1;
  c1_symtab *pcVar2;
  c1_symbol *pcVar3;
  void *pvVar4;
  c1_keyed_list *path_00;
  int *piVar5;
  int *piVar6;
  int *local_1c;
  c1_list_cursor local_18;
  int *local_10;
  int *local_c;
  fe_name **local_8;
  uint step;
  
  local_1c = (int *)0x0;
  pcVar3 = *(c1_symbol **)(*(int *)path + 8);
  if ((pcVar3->kind & 0x1f) == 0xf) {
    if (pcVar3->name == (fe_name *)*state) {
      local_1c = path;
    }
    pcVar3 = g_scope_vector->entries[(short)pcVar3->key_ref];
  }
  list_cursor_init_from_head(&local_18,(pcVar3->x28).members);
  step = 4;
  local_c = (int *)0x0;
  piVar6 = local_18.current;
  local_8 = &pcVar3->name;
  piVar1 = local_1c;
  if (local_18.valid != '\0') {
    local_c = local_18.current;
  }
LAB_104ac647:
  do {
    while( true ) {
      local_1c = piVar1;
      local_10 = local_c;
      if (local_10 == (int *)0x0) {
        return local_1c;
      }
      if ((piVar6 == (int *)0x0) ||
         (local_c = (int *)piVar6[1], piVar6 = local_c, local_18.current = local_c,
         local_c == (int *)0x0)) {
        local_c = (int *)0x0;
      }
      piVar1 = local_1c;
      if ((*(byte *)(local_10 + -2) & 0x1f) != 3) break;
      if (((void *)*local_10 != g_name_vbptr) && ((void *)*local_10 != g_name_vfptr)) {
        return local_1c;
      }
    }
  } while ((((g_compile_flags_cc & 0x100000) != 0) && ((*(byte *)(local_10 + -2) & 0x1f) == 0xf)) &&
          ((*(byte *)((int)local_10 + 0x12) & 2) != 0));
  if ((*(byte *)(local_10 + -2) & 0x1f) != 0xf) {
    return local_1c;
  }
  if ((*(byte *)((int)local_10 + 0x12) & 1) != 0) goto code_r0x104ac6b4;
  goto LAB_104ac72b;
code_r0x104ac6b4:
  if (state[2] == 0) {
    pcVar2 = symtab_new(4,5,0,0,'\x01','\x01');
    state[2] = (int)pcVar2;
    pcVar2 = symtab_new(4,5,0,0,'\x01','\x01');
    state[3] = (int)pcVar2;
  }
  if ((*(byte *)((int)local_10 + 0x12) & 2) == 0) {
    pcVar3 = g_scope_vector->entries[(short)local_10[4]];
  }
  else {
    pcVar3 = (c1_symbol *)0x0;
  }
  pvVar4 = symtab_lookup((c1_symtab *)state[2],pcVar3);
  local_c = local_c;
  piVar6 = local_18.current;
  if (pvVar4 != (void *)0x1) {
    if ((*(byte *)((int)local_10 + 0x12) & 2) == 0) {
      pcVar3 = g_scope_vector->entries[(short)local_10[4]];
    }
    else {
      pcVar3 = (c1_symbol *)0x0;
    }
    symtab_insert((c1_symtab *)state[2],pcVar3,(void *)0x1);
LAB_104ac72b:
    piVar6 = state;
    path_00 = tree_new_list_cell((c1_keyed_list *)0x0,*(int *)path,(c1_symbol *)(local_10 + -2));
    piVar5 = class_find_base_paths(path_00,piVar6);
    local_c = local_c;
    piVar6 = local_18.current;
    if ((piVar5 != (int *)0x0) && (local_c = local_c, piVar1 = piVar5, local_1c != (int *)0x0)) {
      *(int *)(local_1c[1] + 4) = *piVar5;
      local_1c[1] = piVar5[1];
      local_c = local_c;
      piVar1 = local_1c;
    }
  }
  goto LAB_104ac647;
}

