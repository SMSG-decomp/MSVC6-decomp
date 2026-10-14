void __fastcall diag_note_no_copy_constructor(c1_conversion *conv)

{
  char cVar1;
  
  cVar1 = type_compare(conv->source,conv->target,2);
  if (cVar1 != '\0') {
    diag_note(0x179f,conv->source,(conv->source->extra).cls);
    return;
  }
  diag_note(0x1797);
  return;
}

