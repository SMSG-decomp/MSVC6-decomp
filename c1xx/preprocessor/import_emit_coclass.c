void __cdecl import_emit_coclass(void *typeinfo,void *typeattr,wchar_t *name)

{
  void *pThis;
  long lVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  void *guid;
  bool bVar4;
  char *s;
  int *piStack_10;
  wchar_t *pwStack_c;
  void *pvStack_8;
  ulong uStack_4;
  
  import_text_puts(g_import_items,"\nstruct __declspec(uuid(\"");
  guid = typeattr;
  import_write_guid_string(g_import_items,typeattr);
  import_text_printf(g_import_items,"\"))\n%S;\n",name);
  pThis = typeinfo;
  uVar3 = 0;
  if (*(short *)((int)guid + 0x30) != 0) {
    do {
      import_text_puts(g_import_items,"    // ");
      lVar1 = (**(code **)(*(int *)pThis + 0x24))(pThis,(uint)uVar3,(int *)&typeinfo);
      if (lVar1 < 0) {
        diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
      }
      if (((uint)typeinfo & 7) != 0) {
        import_text_puts(g_import_items,"[ ");
        bVar4 = ((uint)typeinfo & 1) == 0;
        if (!bVar4) {
          import_text_puts(g_import_items,"default");
        }
        if (((uint)typeinfo & 2) != 0) {
          if (!bVar4) {
            import_text_puts(g_import_items,", ");
          }
          import_text_puts(g_import_items,"source");
          bVar4 = false;
        }
        if (((uint)typeinfo & 4) != 0) {
          if (!bVar4) {
            import_text_puts(g_import_items,", ");
          }
          import_text_puts(g_import_items,"restricted");
        }
        import_text_puts(g_import_items," ] ");
      }
      lVar1 = (**(code **)(*(int *)pThis + 0x20))(pThis,(uint)uVar3,&uStack_4);
      if (lVar1 < 0) {
        diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
      }
      lVar1 = (**(code **)(*(int *)pThis + 0x38))(pThis,uStack_4,&piStack_10);
      if (lVar1 < 0) {
        diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
      }
      lVar1 = (**(code **)(*piStack_10 + 0xc))(piStack_10,&pvStack_8);
      if (lVar1 < 0) {
        diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
      }
      if (*(int *)((int)pvStack_8 + 0x28) == 3) {
LAB_104a06ee:
        s = "interface";
LAB_104a0647:
        import_text_puts(g_import_items,s);
      }
      else if (*(int *)((int)pvStack_8 + 0x28) == 4) {
        if ((*(byte *)((int)pvStack_8 + 0x36) & 0x40) != 0) goto LAB_104a06ee;
        s = "dispinterface";
        goto LAB_104a0647;
      }
      lVar1 = (**(code **)(*piStack_10 + 0x30))
                        (piStack_10,-1,&pwStack_c,(wchar_t **)0x0,(ulong *)0x0,(wchar_t **)0x0);
      if (lVar1 < 0) {
        diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
      }
      pwVar2 = import_apply_rename(pwStack_c);
      import_text_printf(g_import_items," %S\n",pwVar2);
      SysFreeString(pwStack_c);
      (**(code **)(*piStack_10 + 0x4c))(piStack_10,pvStack_8);
      (**(code **)(*piStack_10 + 8))(piStack_10);
      uVar3 = uVar3 + 1;
      guid = typeattr;
    } while (uVar3 < *(ushort *)((int)typeattr + 0x30));
  }
  import_write_named_guid(guid,"CLS",name);
  return;
}

