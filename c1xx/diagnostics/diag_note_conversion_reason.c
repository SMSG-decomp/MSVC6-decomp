void __fastcall diag_note_conversion_reason(c1_conversion *conv)

{
  diag_note(0x1785,conv->first->source,conv->first->target);
  conv_report_cannot_convert(conv->first,'\0');
  return;
}

