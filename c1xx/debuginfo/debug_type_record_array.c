int __cdecl debug_type_record_array(c1_type *type,uint element_index)

{
  ushort uVar1;
  uint lo;
  int iVar2;
  ushort *body;
  
  body = g_cv_record_body;
  *g_cv_record_body = 0x1003;
  *(uint *)(body + 1) = element_index;
  body[3] = 0x11;
  body[4] = 0;
  if (g_minimal_rebuild != '\0') {
    g_minimal_rebuild_tracker->current->tracked = '\0';
  }
  lo = type_size(type);
  uVar1 = debug_cv_unsigned_numeric_leaf(body + 5,lo,0);
  if (g_minimal_rebuild != '\0') {
    g_minimal_rebuild_tracker->current->tracked = '\x01';
  }
  *(undefined1 *)(uVar1 + 10 + (int)body) = 0;
  iVar2 = cvserver_emit_type(uVar1 + 0xb);
  return iVar2;
}

