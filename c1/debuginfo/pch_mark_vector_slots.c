void __cdecl pch_mark_vector_slots(fe_vector *vec,void *callback)

{
  int iVar1;
  
  if (vec != (fe_vector *)0x0) {
    if (vec->capacity != 0) {
      pch_relocate_slot_once(&g_pch_image,(uint)&vec->data);
    }
    iVar1 = 0;
    if (vec->count != 0) {
      do {
        pch_relocate_slot_once(&g_pch_image,(uint)(vec->data + iVar1));
        if (callback != (void *)0x0) {
          (*callback)(vec->data[iVar1]);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)vec->count);
    }
  }
  return;
}

