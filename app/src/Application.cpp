#include "Application.h"
//
//void Application::printInfo() {
//    for(const auto& i : m_info) {
//        std::cout << i << std::endl;
//    }
//}
//
//void Application::setFileToInfo(const FileTags &infoAboutFile) {
//    m_info.push_back(infoAboutFile);
//}
//
//void Application::setTag(const std::string& nameOfFile, const std::string& nameOfTag, const std::string& content) {
//    auto iter = find_if(m_info.begin(), m_info.end(), [&](FileTags& file) {
//        return file.getTag("filename") == nameOfFile;
//    });
//
//    iter->setInfo(nameOfTag, content);
//}
