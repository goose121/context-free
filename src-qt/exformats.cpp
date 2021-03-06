#include "exformats.h"

#include <SVGCanvas.h>
#include <pngCanvas.h>
#ifdef QUICKTIME
#include <ffCanvas.h>
#endif /* QUICKTIME */
#include <cfdg.h>

#include <QErrorMessage>
#include <QDoubleSpinBox>
#include <QSettings>
#include <QtDebug>
#include <memory>
#include <string>

std::shared_ptr<Canvas> ex_svg(int frames, int w, int h, char *ofile, aggCanvas::PixelFormat &fmt, std::shared_ptr<Renderer> rend) {
    return std::make_shared<SVGCanvas>(ofile, w, h, false);
}

std::shared_ptr<Canvas> ex_png(int frames, int w, int h, char *ofile, aggCanvas::PixelFormat &p, std::shared_ptr<Renderer> rend) {

    // If a static output file name is provided then generate an output
    // file name format string by escaping any '%' characters. If this is
    // an animation run with PNG output then add "_%f" before the extension
    std::string pngOutput;
    std::string fname(ofile);
    pngOutput.reserve(fname.length());
    for (char c: fname) {
        pngOutput.append(c == '%' ? 2 : 1, c);
    }
    size_t ext = pngOutput.find_last_of('.');
    size_t dir = pngOutput.find_last_of('/');
    if(frames > 1)
    if (ext != std::string::npos && (dir == std::string::npos || ext > dir)) {
        pngOutput.insert(ext, "_%f");
    } else {
        pngOutput.append("_%f");
    }

    char *pngOutputC = new char[pngOutput.length()+1];
    strcpy(pngOutputC, pngOutput.c_str());

    delete ofile;
    return std::make_shared<pngCanvas>(pngOutputC, false, w, h, p, false, frames, 294, true, rend.get(), 1, 1);
}

#ifdef QUICKTIME
std::shared_ptr<Canvas> ex_qtime(int frames, int w, int h, char *ofile, aggCanvas::PixelFormat &p, std::shared_ptr<Renderer> rend) {
    // Uncomment to enable Quicktime support

    QSettings s("contextfreeart.org", "ContextFree");
    qDebug() << "Creating ffCanvas @" << s.value("output_fps", 30).toInt() << "fps";
    qDebug() << "File is" << ofile;
    std::shared_ptr<ffCanvas> canv = std::make_shared<ffCanvas>(ofile, p, w, h, s.value("output_fps", 30).toInt(), ffCanvas::H264);
    if(canv->mErrorMsg) {
        std::cerr << "ffCanvas error: " << canv->mErrorMsg << std::endl;
    }
    return canv;
    return nullptr;
}
#endif /* QUICKTIME */
