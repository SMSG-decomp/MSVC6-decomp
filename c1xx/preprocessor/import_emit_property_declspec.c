void __cdecl
import_emit_property_declspec
          (void *typeinfo,void *get_funcdesc,void *put_funcdesc,wchar_t *class_name)

{
  void *a;
  short sVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  wchar_t *_Str2;
  char *pcVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  void *a_00;
  wchar_t *local_8;
  wchar_t *pwStack_4;
  
  if (get_funcdesc == (void *)0x0) {
    iVar4 = *(int *)((int)put_funcdesc + 0xc);
  }
  else {
    iVar4 = *(int *)((int)get_funcdesc + 0xc);
  }
  if (iVar4 != 4) {
    if (get_funcdesc != (void *)0x0) {
      if (*(int *)((int)get_funcdesc + 0xc) != 1) {
        return;
      }
      if (*(short *)((int)get_funcdesc + 0x24) != 0x19) {
        return;
      }
      if (*(short *)((int)get_funcdesc + 0x18) < 1) {
        return;
      }
      iVar5 = *(int *)((int)get_funcdesc + 8);
      iVar8 = 0;
      iVar9 = *(short *)((int)get_funcdesc + 0x18) + -1;
      if (0 < iVar9) {
        do {
          if ((*(byte *)(iVar5 + 0xc) & 0xb) != 1) {
            return;
          }
          iVar8 = iVar8 + 1;
          iVar5 = iVar5 + 0x10;
        } while (iVar8 < iVar9);
      }
      if ((*(byte *)(iVar5 + 0xc) & 0xb) != 10) {
        return;
      }
      if (*(short *)(iVar5 + 4) != 0x1a) {
        return;
      }
    }
    if (put_funcdesc != (void *)0x0) {
      if (*(int *)((int)put_funcdesc + 0xc) != 1) {
        return;
      }
      if (*(short *)((int)put_funcdesc + 0x24) != 0x19) {
        return;
      }
      sVar1 = *(short *)((int)put_funcdesc + 0x18);
      if (sVar1 < 1) {
        return;
      }
      iVar9 = 0;
      if (0 < sVar1) {
        pbVar7 = (byte *)(*(int *)((int)put_funcdesc + 8) + 0xc);
        do {
          if ((*pbVar7 & 0xb) != 1) {
            return;
          }
          iVar9 = iVar9 + 1;
          pbVar7 = pbVar7 + 0x10;
        } while (iVar9 < sVar1);
      }
    }
  }
  else {
    if (get_funcdesc != (void *)0x0) {
      if (*(short *)((int)get_funcdesc + 0x24) == 0x18) {
        return;
      }
      iVar9 = 0;
      if (0 < *(short *)((int)get_funcdesc + 0x18)) {
        pbVar7 = (byte *)(*(int *)((int)get_funcdesc + 8) + 0xc);
        do {
          if (((*pbVar7 & 0xb) != 1) && ((*pbVar7 & 0xb) != 0)) {
            return;
          }
          iVar9 = iVar9 + 1;
          pbVar7 = pbVar7 + 0x10;
        } while (iVar9 < *(short *)((int)get_funcdesc + 0x18));
      }
    }
    if (put_funcdesc != (void *)0x0) {
      if (*(short *)((int)put_funcdesc + 0x24) != 0x18) {
        return;
      }
      sVar1 = *(short *)((int)put_funcdesc + 0x18);
      if (sVar1 < 1) {
        return;
      }
      iVar9 = 0;
      if (0 < sVar1) {
        pbVar7 = (byte *)(*(int *)((int)put_funcdesc + 8) + 0xc);
        do {
          if (((*pbVar7 & 0xb) != 1) && ((*pbVar7 & 0xb) != 0)) {
            return;
          }
          iVar9 = iVar9 + 1;
          pbVar7 = pbVar7 + 0x10;
        } while (iVar9 < sVar1);
      }
    }
  }
  if (get_funcdesc == (void *)0x0) {
    lVar3 = (**(code **)(*(int *)typeinfo + 0x30))
                      (typeinfo,*(long *)put_funcdesc,&local_8,(wchar_t **)0x0,(ulong *)0x0,
                       (wchar_t **)0x0);
    if (lVar3 < 0) {
      diag_fatal_file(lVar3,0x54,0x166,g_import_file_as_written);
    }
    iVar9 = *(short *)((int)put_funcdesc + 0x18) + -1;
    a_00 = (void *)(iVar9 * 0x10 + *(int *)((int)put_funcdesc + 8));
  }
  else {
    lVar3 = (**(code **)(*(int *)typeinfo + 0x30))
                      (typeinfo,*(long *)get_funcdesc,&local_8,(wchar_t **)0x0,(ulong *)0x0,
                       (wchar_t **)0x0);
    if (lVar3 < 0) {
      diag_fatal_file(lVar3,0x54,0x166,g_import_file_as_written);
    }
    iVar9 = (int)*(short *)((int)get_funcdesc + 0x18);
    if (iVar4 != 4) {
      iVar9 = iVar9 + -1;
      a_00 = *(void **)(iVar9 * 0x10 + *(int *)((int)get_funcdesc + 8));
    }
    else {
      a_00 = (void *)((int)get_funcdesc + 0x20);
    }
    if (put_funcdesc != (void *)0x0) {
      if ((*(int *)((int)get_funcdesc + 0xc) == *(int *)((int)put_funcdesc + 0xc)) &&
         ((int)*(short *)((int)put_funcdesc + 0x18) == iVar9 + 1)) {
        bVar2 = import_typedesc_differ
                          (a_00,(void *)(iVar9 * 0x10 + *(int *)((int)put_funcdesc + 8)));
        if (bVar2 == 0) {
          lVar3 = (**(code **)(*(int *)typeinfo + 0x30))
                            (typeinfo,*(long *)put_funcdesc,&pwStack_4,(wchar_t **)0x0,(ulong *)0x0,
                             (wchar_t **)0x0);
          if (lVar3 < 0) {
            diag_fatal_file(lVar3,0x54,0x166,g_import_file_as_written);
          }
          iVar4 = wcscmp(local_8,pwStack_4);
          if (iVar4 != 0) {
            SysFreeString(pwStack_4);
            SysFreeString(local_8);
            return;
          }
          SysFreeString(pwStack_4);
          iVar4 = 0;
          if (0 < iVar9) {
            do {
              a = (void *)(iVar9 * 0x10 + *(int *)((int)put_funcdesc + 8));
              bVar2 = import_typedesc_differ(a,a);
              if (bVar2 != 0) {
                SysFreeString(local_8);
                return;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar9);
          }
          goto LAB_1049f2d3;
        }
      }
      SysFreeString(local_8);
      return;
    }
  }
LAB_1049f2d3:
  _Str2 = import_apply_rename(local_8);
  iVar4 = wcscmp(class_name,_Str2);
  import_text_puts(g_import_member_property_data,"    __declspec(property(");
  if (get_funcdesc != (void *)0x0) {
    import_text_printf(g_import_member_property_data,"get=%s%S",g_import_high_get_prefix,_Str2);
  }
  if (put_funcdesc != (void *)0x0) {
    if (get_funcdesc != (void *)0x0) {
      import_text_putc(g_import_member_property_data,0x2c);
    }
    pcVar6 = g_import_high_putref_prefix;
    if (*(int *)((int)put_funcdesc + 0x10) != 8) {
      pcVar6 = g_import_high_put_prefix;
    }
    import_text_printf(g_import_member_property_data,"put=%s%S",pcVar6,_Str2);
  }
  import_text_puts(g_import_member_property_data,"))\n    ");
  import_write_wrapper_type(g_import_member_property_data,a_00,typeinfo,0);
  pcVar6 = "_";
  if (iVar4 != 0) {
    pcVar6 = "";
  }
  import_text_printf(g_import_member_property_data," %s%S",pcVar6,_Str2);
  if (0 < iVar9) {
    do {
      import_text_puts(g_import_member_property_data,"[]");
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  import_text_puts(g_import_member_property_data,";\n");
  SysFreeString(local_8);
  return;
}

