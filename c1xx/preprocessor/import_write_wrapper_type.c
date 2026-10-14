int __cdecl
import_write_wrapper_type(c1_il_buffer *buf,void *typedesc,void *typeinfo,int qualify_own)

{
  int iVar1;
  void *typedesc_00;
  void *typeinfo_00;
  byte bVar2;
  bool bVar3;
  long lVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  wchar_t *pwStack_c;
  c1_itypeinfo *pcStack_8;
  c1_typeattr *pcStack_4;
  
  typeinfo_00 = typeinfo;
  typedesc_00 = typedesc;
  switch(*(short *)((int)typedesc + 4)) {
  case 8:
    import_text_puts(buf,g_import_bstr_type);
    return (-(uint)(g_import_raw_native_types != 0) & 0xfffffffe) + 2;
  case 9:
  case 0xd:
    if (g_import_raw_native_types == 0) {
      pcVar6 = "IDispatch";
      if (*(short *)((int)typedesc + 4) != 9) {
        pcVar6 = "IUnknown";
      }
      import_text_printf(buf,"%s%s",pcVar6,g_import_smartptr_suffix);
      return 1;
    }
    break;
  case 0xc:
    import_text_puts(buf,g_import_variant_type);
    return (-(uint)(g_import_raw_native_types != 0) & 0xfffffffd) + 3;
  case 0x1a:
    if ((g_import_raw_native_types == 0) && ((short)(*(uint **)typedesc)[1] == 0x1d)) {
      bVar2 = import_get_ref_type_info(typeinfo,**(uint **)typedesc,&typedesc);
      if (bVar2 == 0) {
        import_text_puts(buf,"__missing_type__");
        return 0;
      }
      lVar4 = (**(code **)(*(int *)typedesc + 0xc))(typedesc,&typeinfo);
      if (lVar4 < 0) {
        diag_fatal_file(lVar4,0x54,0x166,g_import_file_as_written);
      }
      iVar1 = *(int *)((int)typeinfo + 0x28);
      if (iVar1 == 5) {
        bVar3 = import_coclass_default_interface(typedesc,typeinfo,&pcStack_8,&pcStack_4);
        (**(code **)(*(int *)typedesc + 0x4c))(typedesc,typeinfo);
        (**(code **)(*(int *)typedesc + 8))(typedesc);
        if (bVar3) {
          typedesc = pcStack_8;
          typeinfo = pcStack_4;
LAB_1049c389:
          pwVar5 = import_namespace_for_typeinfo(typedesc,(char)qualify_own);
          if (pwVar5 != (wchar_t *)0x0) {
            import_text_printf(buf,"%S::",pwVar5);
          }
          lVar4 = (**(code **)(*(int *)typedesc + 0x30))
                            (typedesc,-1,&pwStack_c,(wchar_t **)0x0,(ulong *)0x0,(wchar_t **)0x0);
          if (lVar4 < 0) {
            diag_fatal_file(lVar4,0x54,0x166,g_import_file_as_written);
          }
          pcVar6 = g_import_smartptr_suffix;
          pwVar5 = import_apply_rename(pwStack_c);
          import_text_printf(buf,"%S%s",pwVar5,pcVar6);
          SysFreeString(pwStack_c);
          (**(code **)(*(int *)typedesc + 0x4c))(typedesc,typeinfo);
          (**(code **)(*(int *)typedesc + 8))(typedesc);
          return 1;
        }
      }
      else {
        if ((iVar1 == 3) || (iVar1 == 4)) goto LAB_1049c389;
        (**(code **)(*(int *)typedesc + 0x4c))(typedesc,typeinfo);
        (**(code **)(*(int *)typedesc + 8))(typedesc);
      }
    }
  }
  import_write_typedesc(buf,typedesc_00,typeinfo_00,(wchar_t *)0x0,0);
  return 0;
}

