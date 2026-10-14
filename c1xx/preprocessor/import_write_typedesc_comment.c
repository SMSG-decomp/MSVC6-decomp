void __cdecl import_write_typedesc_comment(c1_il_buffer *buf,c1_typedesc *typedesc,void *typeinfo)

{
  c1_u16 cVar1;
  ushort uVar2;
  c1_arraydesc *adesc;
  
  cVar1 = typedesc->vt;
  if (cVar1 == 0x1a) {
    import_write_typedesc_comment(buf,(typedesc->u).lptdesc,typeinfo);
    import_text_puts(buf," *");
  }
  else {
    if (cVar1 == 0x1b) {
      import_text_puts(buf,"SAFEARRAY(");
      import_write_typedesc_comment(buf,(typedesc->u).lptdesc,typeinfo);
      import_text_putc(buf,0x29);
      return;
    }
    if (cVar1 != 0x1c) {
      import_write_typedesc(buf,typedesc,typeinfo,(wchar_t *)0x0,0);
      return;
    }
    adesc = (typedesc->u).lpadesc;
    import_write_typedesc_comment(buf,&adesc->tdescElem,typeinfo);
    uVar2 = 0;
    if (adesc->cDims != 0) {
      do {
        import_text_putc(buf,0x5b);
        import_text_printf(buf,"%lu",adesc->rgbounds[uVar2].cElements);
        import_text_putc(buf,0x5d);
        uVar2 = uVar2 + 1;
      } while (uVar2 < adesc->cDims);
      return;
    }
  }
  return;
}

