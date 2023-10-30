stock ColorUtils_RGBA(r, g, b, a) {
    return (_:a << 24) | (_:r << 16) | (_:g << 8) | _:b;
}

stock Float:ColorUtils_RGBA1(Float:r, Float:g, Float:b, Float:a) {
    return Float:(_:a << 24) | Float:(_:r << 16) | Float:(_:g << 8) | Float:(_:b);
}


stock ColorUtils_GetRed(color) {
    return (color >> 16) & 0xFF;
}

stock ColorUtils_GetGreen(color) {
    return (color >> 8) & 0xFF;
}

stock ColorUtils_GetBlue(color) {
    return color & 0xFF;
}

stock ColorUtils_GetAlpha(color) {
    return (color >> 24) & 0xFF;
}


stock ColorUtils_CreateColor(r, g, b, a) {
    return (_:a << 24) | (_:r << 16) | (_:g << 8) | _:b;
}

stock ColorUtils_SetAlpha(&color, a) {
    color = (color & 0x00FFFFFF) | (a << 24);
}

stock ColorUtils_Interpolate(startColor, endColor, progress) {
    new startR = ColorUtils_GetRed(startColor);
    new startG = ColorUtils_GetGreen(startColor);
    new startB = ColorUtils_GetBlue(startColor);
    new startA = ColorUtils_GetAlpha(startColor);

    new endR = ColorUtils_GetRed(endColor);
    new endG = ColorUtils_GetGreen(endColor);
    new endB = ColorUtils_GetBlue(endColor);
    new endA = ColorUtils_GetAlpha(endColor);

    new interpolatedR = startR + (endR - startR) * progress;
    new interpolatedG = startG + (endG - startG) * progress;
    new interpolatedB = startB + (endB - startB) * progress;
    new interpolatedA = startA + (endA - startA) * progress;

    return ColorUtils_RGBA(interpolatedR, interpolatedG, interpolatedB, interpolatedA);
}

stock Float:ColorUtils_MixColor(color1, color2, Float:ratio) {
    new r1 = ColorUtils_GetRed(color1);
    new g1 = ColorUtils_GetGreen(color1);
    new b1 = ColorUtils_GetBlue(color1);
    new a1 = ColorUtils_GetAlpha(color1);

    new r2 = ColorUtils_GetRed(color2);
    new g2 = ColorUtils_GetGreen(color2);
    new b2 = ColorUtils_GetBlue(color2);
    new a2 = ColorUtils_GetAlpha(color2);

    // Mix the colors based on the given ratio
    new Float:mixedR = r1 * (1.0 - ratio) + r2 * ratio;
    new Float:mixedG = g1 * (1.0 - ratio) + g2 * ratio;
    new Float:mixedB = b1 * (1.0 - ratio) + b2 * ratio;
    new Float:mixedA = a1 * (1.0 - ratio) + a2 * ratio;

    return ColorUtils_RGBA1(_:mixedR, _:mixedG, _:mixedB, _:mixedA);
}

