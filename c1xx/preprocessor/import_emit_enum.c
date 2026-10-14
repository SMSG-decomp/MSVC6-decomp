void __cdecl import_emit_enum(void *typeinfo,void *typeattr,wchar_t *name)

{
  void *pvVar1;
  byte bVar2;
  ushort uVar3;
  void *pvVar4;
  long lVar5;
  wchar_t *name_00;
  int iVar6;
  char *pcVar7;
  wchar_t *pwStack_1c;
  int iStack_18;
  char *pcStack_14;
  ushort value_variant [4];
  int iStack_8;
  
  pvVar1 = typeattr;
  if (*(short *)((int)typeattr + 0x2e) != 0) {
    if (g_import_enum_table == (c1_import_enum_table *)0x0) {
      pvVar4 = __2_YAPAXI_Z(0x40c);
      if (pvVar4 == (void *)0x0) {
        g_import_enum_table = (c1_import_enum_table *)0x0;
LAB_1049fbf6:
        diag_fatal_simple(0x3c);
      }
      g_import_enum_table = import_enum_table_init(pvVar4);
      if (g_import_enum_table == (c1_import_enum_table *)0x0) goto LAB_1049fbf6;
    }
    import_text_printf(g_import_items,"\nenum %S\n{\n",name);
    pvVar4 = typeinfo;
    uVar3 = 0;
    if (*(short *)((int)pvVar1 + 0x2e) != 0) {
      do {
        lVar5 = (**(code **)(*(int *)pvVar4 + 0x18))(pvVar4,(uint)uVar3,&typeinfo);
        if (lVar5 < 0) {
          diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
        }
        lVar5 = (**(code **)(*(int *)pvVar4 + 0x30))
                          (pvVar4,*(long *)typeinfo,&pwStack_1c,(wchar_t **)0x0,(ulong *)0x0,
                           (wchar_t **)0x0);
        if (lVar5 < 0) {
          diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
        }
        name_00 = import_apply_rename(pwStack_1c);
        VariantInit(value_variant);
        VariantCopy(value_variant,*(void **)((int)typeinfo + 8));
        lVar5 = VariantChangeType(value_variant,value_variant,0,3);
        if (lVar5 < 0) {
          diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
        }
        VariantClear(value_variant);
        bVar2 = import_enum_table_find(g_import_enum_table,name_00);
        if (bVar2 == 0) {
          import_name_list_push(g_import_enum_table,name,iStack_8);
          pcVar7 = "    ";
        }
        else {
          import_enum_table_get(g_import_enum_table,&pcStack_14,&iStack_18);
          if (iStack_18 != iStack_8) {
            import_text_printf(g_import_items,
                               "#pragma message(\"enum %S member %S=%d already seen in enum %s as %S=%d\")\n"
                               ,name,name_00,iStack_8,pcStack_14,name_00,iStack_18);
          }
          pcVar7 = "//  ";
        }
        import_text_puts(g_import_items,pcVar7);
        iVar6 = wcscmp(name,name_00);
        pcVar7 = "_";
        if (iVar6 != 0) {
          pcVar7 = "";
        }
        import_text_printf(g_import_items,"%s%S = %d",pcVar7,name_00,iStack_8);
        pvVar1 = typeattr;
        if (uVar3 + 1 != (uint)*(ushort *)((int)typeattr + 0x2e)) {
          import_text_putc(g_import_items,0x2c);
        }
        import_text_putc(g_import_items,10);
        SysFreeString(pwStack_1c);
        (**(code **)(*(int *)pvVar4 + 0x54))(pvVar4,typeinfo);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ushort *)((int)pvVar1 + 0x2e));
    }
    import_text_puts(g_import_items,"};\n");
  }
  return;
}

