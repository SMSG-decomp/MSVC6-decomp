void __cdecl decl_check_multiple_storage_classes(c1_specifier_words *words)

{
  byte bVar1;
  char in_stack_00000014;
  void *in_stack_00000018;
  
  diag_error(0x9f);
  switch(in_stack_00000014) {
  case '\x03':
  case '\x0e':
    if ((words->inlining & 1) == 0) {
      words->inlining = words->inlining | 1;
      return;
    }
    bVar1 = 0xe;
    goto LAB_10627eff;
  case '\x04':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((words->declspec & 1) == 0) {
      words->declspec = words->declspec | 1;
      return;
    }
    break;
  case '\x05':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((words->declspec & 2) == 0) {
      words->declspec = words->declspec | 2;
      return;
    }
    break;
  case '\x06':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((words->declspec & 0xc) == 0) {
      words->declspec = words->declspec | 8;
      return;
    }
    break;
  case '\a':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((words->declspec & 0xc) == 0) {
      words->declspec = words->declspec | 4;
      return;
    }
    break;
  case '\b':
    bVar1 = words->allocate;
    if ((bVar1 & 1) == 0) {
      if (in_stack_00000018 == (void *)0x0) {
        words->segment = (void *)0x0;
        words->allocate = bVar1 & 0xfe;
        return;
      }
      words->segment = in_stack_00000018;
      words->allocate = bVar1 | 1;
      return;
    }
    break;
  default:
    goto switchD_1060846b_caseD_9;
  case '\n':
    (*g_idb->vtbl->idb_note_decl_specifier)(g_idb);
    if ((words->declspec & 0x40) == 0) {
      words->declspec = words->declspec | 0x40;
      words->storage = words->storage | 0x40;
      return;
    }
    break;
  case '\x12':
    if ((words->flags8 & 2) == 0) {
      words->flags8 = words->flags8 | 2;
      return;
    }
    break;
  case -0x14:
    if ((words->inlining & 1) == 0) {
      words->inlining = words->inlining | 9;
      return;
    }
    bVar1 = 0xec;
    goto LAB_10627eff;
  }
  bVar1 = 6;
LAB_10627eff:
  if (in_stack_00000014 == '\b') {
    diag_warning(1,0x8d,"allocate");
    return;
  }
  if (bVar1 == 6) {
    diag_warning(1,0x8d,g_last_name->text);
    return;
  }
  diag_warning(1,0x8d,g_token_spelling[bVar1]);
switchD_1060846b_caseD_9:
  return;
}

