bool __cdecl
import_coclass_default_interface
          (c1_itypeinfo *typeinfo,void *typeattr,c1_itypeinfo **out_typeinfo,
          c1_typeattr **out_typeattr)

{
  c1_itypeinfo *pThis;
  void *pvVar1;
  long lVar2;
  uint uVar3;
  uint index;
  uint uVar4;
  ulong uStack_8;
  c1_typeattr *pcStack_4;
  
  pvVar1 = typeattr;
  pThis = typeinfo;
  uVar3 = 0xffffffff;
  uVar4 = 0;
  if (*(short *)((int)typeattr + 0x30) != 0) {
    do {
      index = uVar4;
      lVar2 = (*pThis->vtbl->GetImplTypeFlags)(pThis,index,(int *)&typeinfo);
      if (lVar2 < 0) {
        diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
      }
      if (((uint)typeinfo & 6) == 0) {
        if (((uint)typeinfo & 1) != 0) break;
        if (uVar3 == 0xffffffff) {
          uVar3 = index;
        }
      }
      uVar4 = index + 1;
      index = uVar3;
    } while (uVar4 < *(ushort *)((int)pvVar1 + 0x30));
    if (index != 0xffffffff) {
      lVar2 = (*pThis->vtbl->GetRefTypeOfImplType)(pThis,index,&uStack_8);
      if (lVar2 < 0) {
        diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
      }
      lVar2 = (*pThis->vtbl->GetRefTypeInfo)(pThis,uStack_8,&typeattr);
      if (lVar2 < 0) {
        diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
      }
      lVar2 = (**(code **)(*(int *)typeattr + 0xc))(typeattr,&pcStack_4);
      if (lVar2 < 0) {
        diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
      }
      if ((pcStack_4->typekind != 3) && (pcStack_4->typekind != 4)) {
        (**(code **)(*(int *)typeattr + 0x4c))(typeattr,pcStack_4);
        (**(code **)(*(int *)typeattr + 8))(typeattr);
        *out_typeinfo = (c1_itypeinfo *)0x0;
        *out_typeattr = (c1_typeattr *)0x0;
        return false;
      }
      *out_typeinfo = typeattr;
      *out_typeattr = pcStack_4;
      return true;
    }
  }
  *out_typeinfo = (c1_itypeinfo *)0x0;
  *out_typeattr = (c1_typeattr *)0x0;
  return false;
}

