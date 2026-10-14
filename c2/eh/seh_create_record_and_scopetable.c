void __fastcall seh_create_record_and_scopetable(c2_function *fn)

{
  char cVar1;
  c2_seh_try_scope *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = 0;
  for (pcVar2 = fn->seh_try_scopes; pcVar2 != (c2_seh_try_scope *)0x0; pcVar2 = pcVar2->next) {
    iVar5 = iVar5 + 1;
  }
  if (g_opt_basic != 0) {
    if (g_seh_param_storage == (c2_symbol *)0x0) {
      g_vb_seh_prefix_size = 0;
      g_seh_record = create_frame_eh_record(0xc,1,"__$SEHRec");
      return;
    }
    g_vb_seh_prefix_size = g_seh_param_storage->size;
    g_seh_record = create_frame_eh_record(g_vb_seh_prefix_size + 0xc,1,"__$SEHRec");
    seh_rebase_record_parts(fn,g_seh_record,g_seh_param_storage);
    g_seh_param_storage = (c2_symbol *)0x0;
    return;
  }
  g_seh_scopetable = fe_symbol_new_local_cur(6,iVar5 * 0xc,4,1,'\x04',0x80);
  if (g_opt_edit_and_continue != 0) {
    pcVar3 = fn->fsym->name;
    if (pcVar3 == (char *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\ehgen.c",0x69);
    }
    uVar6 = 0xffffffff;
    pcVar4 = pcVar3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = arena_alloc(0,~uVar6 + 0xb);
    sprintf(pcVar4,"__sehtable$%s",pcVar3);
    g_seh_scopetable->name = pcVar4;
  }
  seh_build_scopetable();
  note_symbol_referenced(g_seh_scopetable);
  g_seh_record = create_frame_eh_record(0x18,1,"__$SEHRec");
  return;
}

