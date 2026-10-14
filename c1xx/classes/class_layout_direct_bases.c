void __cdecl class_layout_direct_bases(c1_symbol *cls)

{
  void *pvVar1;
  int iVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  byte local_1e;
  c1_symbol *local_1c;
  c1_member_iter local_18;
  
  local_1c = (c1_symbol *)0x0;
  local_1e = 1;
  do {
    class_member_iter_init(&local_18,&cls->name,4);
LAB_10434af9:
    do {
      local_18.current = local_18.next;
      if (local_18.next == (int *)0x0) break;
      iVar2 = class_member_iter_step(&local_18.cursor);
      pvVar1 = local_18.current;
      local_18.next = (void *)(-(uint)((char)iVar2 != '\0') & (uint)local_18.cursor.current);
      if ((*(byte *)((int)local_18.current + -8) & 0x1f) != 3) {
        if (((g_compile_flags_cc & 0x100000) == 0) ||
           (((*(byte *)((int)local_18.current + -8) & 0x1f) != 0xf ||
            ((*(byte *)((int)local_18.current + 0x12) & 2) == 0)))) {
          if ((*(byte *)((int)local_18.current + -8) & 0x1f) != 0xf) break;
          if ((g_compile_flags_cc & 0x100000) != 0) {
            if ((*(byte *)((int)local_18.current + 0x12) & 2) == 0) {
              pcVar3 = g_scope_vector->entries[(short)*(int *)((int)local_18.current + 0x10)];
            }
            else {
              pcVar3 = (c1_symbol *)0x0;
            }
            if (cls->name == pcVar3->name) goto LAB_10434af9;
          }
          bVar4 = *(byte *)((int)local_18.current + 0x12) & 2;
          if (bVar4 == 0) {
            pcVar3 = g_scope_vector->entries[(short)*(int *)((int)local_18.current + 0x10)];
          }
          else {
            pcVar3 = (c1_symbol *)0x0;
          }
          if ((((pcVar3->detail).cls)->layout_flags3a >> 6 & 1) == local_1e) {
            if ((*(byte *)((int)local_18.current + 0x12) & 1) == 0) {
              if (bVar4 == 0) {
                pcVar3 = g_scope_vector->entries[(short)*(int *)((int)local_18.current + 0x10)];
              }
              else {
                pcVar3 = (c1_symbol *)0x0;
              }
              iVar2 = class_layout_nonvirtual_base(pcVar3,&local_1c,cls);
              *(int *)((int)pvVar1 + 0xc) = iVar2;
            }
            if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')
               ) {
              if ((*(byte *)((int)local_18.current + 0x12) & 2) == 0) {
                pcVar3 = g_scope_vector->entries[(short)*(int *)((int)local_18.current + 0x10)];
              }
              else {
                pcVar3 = (c1_symbol *)0x0;
              }
              mre_note_class_layout_use(g_minimal_rebuild_tracker,pcVar3);
              if (local_1e != 0) {
                if ((*(byte *)((int)local_18.current + 0x12) & 2) == 0) {
                  pcVar3 = g_scope_vector->entries[(short)*(int *)((int)local_18.current + 0x10)];
                }
                else {
                  pcVar3 = (c1_symbol *)0x0;
                }
                mre_note_class_use(g_minimal_rebuild_tracker,pcVar3);
              }
            }
          }
        }
        goto LAB_10434af9;
      }
    } while ((*(void **)local_18.current == g_name_vbptr) ||
            (*(void **)local_18.current == g_name_vfptr));
    if (local_1e == 0) {
      return;
    }
    local_1e = 0;
  } while( true );
}

