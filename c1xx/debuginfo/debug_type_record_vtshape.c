int __cdecl debug_type_record_vtshape(c1_symbol *cls)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  c1_vtable_slot_iter local_c;
  ushort *body;
  
  body = g_cv_record_body;
  *g_cv_record_body = 10;
  vtable_entry_iterator_init(&local_c,*((cls->detail).cls)->vftables->data);
  uVar5 = 0;
  uVar3 = class_vtable_entry_iterator_next((int *)&local_c);
  cVar2 = (char)uVar3;
  while( true ) {
    if (cVar2 == '\0') {
      body[1] = (ushort)uVar5;
      iVar4 = cvserver_emit_type((short)((int)(uVar5 + 1) >> 1) + 4);
      return iVar4;
    }
    iVar4 = (int)uVar5 >> 1;
    if ((uVar5 & 1) == 0) {
      *(undefined1 *)(iVar4 + 4 + (int)body) = 0x50;
    }
    else {
      pbVar1 = (byte *)(iVar4 + 4 + (int)body);
      *pbVar1 = *pbVar1 | 5;
    }
    if (0xfafd < iVar4 + 4U) break;
    uVar5 = uVar5 + 1;
    uVar3 = class_vtable_entry_iterator_next((int *)&local_c);
    cVar2 = (char)uVar3;
  }
  diag_fatal_simple(0x43);
}

